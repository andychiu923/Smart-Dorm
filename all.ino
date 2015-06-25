#include <dht.h>
#include <math.h>
#include <IRremote.h>
#include <Servo.h> 

//AC

long ac_temp[11] = {//ac_temp 0:on 1:off type 2:28C ~ 10:20C
  0x477FB8EC,
  0x677FB8EC,
  0x477FB8F8,
  0x477FB8E4,
  0x477FB8F4,
  0x477FB8EC,
  0x477FB8FC,
  0x477FB8E2,
  0x477FB8F2,
  0x477FB8EA,
  0x477FB8FA
};
unsigned int buffer_ir[134];
IRsend test; //ir pin 3

//DHT

#define dht_dpin 8
dht DHT;
double Td;
double THI;
int light;
  
//SERVO
Servo myservo1;  
Servo myservo2; 

//people and door
int door_state = 0; //0:close 1:open
long long  door_timer, people_timer,people_leaving_timer;
int people = 1;
int current_f = 0;
int current_b = 0;
int next_f = 0;
int next_b = 0;

int lock=0;
int lock2=0;

void setup() {
  Serial.begin(9600);
  
  pinMode(4, INPUT);//f_laser
  pinMode(5, INPUT);//b_laser
  
  pinMode(2,INPUT);//door  
  //attachInterrupt(0, door, FALLING);//pin2  
  door_timer = millis();
  people_timer = millis();
  people_leaving_timer=millis();
  
  delay(700);             //Wait rest of 1000ms recommended delay before

  //accessing sensor
}

void loop() {
  if(people<0){
    people=0;
  }
  if(people>10){
    people=10;
  }
  
  if (digitalRead(2) == HIGH) {
    door_state = 0;
  }  
  else{
    door_state=1;
  }
  
  
  if (digitalRead(4) == LOW) {
    next_f = 1;
  }
  else {
    next_f = 0;
    
  }

  if (digitalRead(5) == LOW) {
    next_b = 1;
    //Serial.println("a");
  }
  else {
    next_b = 0;
    //Serial.println("b");
  }
//if ( (current_f == 0 && current_b == 1 && next_f == 1 && next_b == 0) || (current_f == 1 && current_b == 1 && next_f == 1 && next_b == 0) ) {
  if ( (current_f == 0 && current_b == 0 && next_f == 0 && next_b == 1) ) {
  
    if ( (millis() - people_timer > 1000) && door_state==1 ) {
      people_timer=millis();
      people = people - 1;
      //Serial.println(people);
    }
  }
  //if ( (current_f == 1 && current_b == 0 && next_f == 0 && next_b == 1) || (current_f == 1 && current_b == 1 && next_f == 0 && next_b == 1)) {
     if ( (current_f == 0 && current_b == 0 && next_f == 1 && next_b == 0) ) {
    if(  (millis() - people_timer > 1000) && door_state==1) {
      people_timer=millis();
      people = people + 1;
      //Serial.println(people);
    }
  

  }
  current_f = next_f;
  current_b = next_b;

  if(people>0 && lock2!=1){
     myservo2.attach(7);//light front on
     delay(15);
     myservo2.write(102);
     delay(150);
     myservo2.write(81); 		   
     myservo2.detach();
     
      myservo1.attach(6);//light back on
      delay(15);
      myservo1.write(102);
      delay(150);
      myservo1.write(73); 		   
      delay(15);
      myservo1.detach();
      
      fill_buffer(0); //ac turn on
      test.sendRaw(buffer_ir, 134, 38);
                
    lock=0;
    lock2=1;
  }  

  if(people==0 && lock!=1){
     myservo2.attach(7);//light front off
     delay(15);
     myservo2.write(60);
     delay(150);
     myservo2.write(81); 		   
     myservo2.detach();
     
      myservo1.attach(6);//light back off
      delay(15);
      myservo1.write(45);
      delay(150);
      myservo1.write(73); 		   
      delay(15);
      myservo1.detach();
      
      fill_buffer(1); //ac turn off
      test.sendRaw(buffer_ir, 134, 38);
      
      lock2=0;
      lock=1;
  }

  if(Serial.available() > 0) {
    char a = Serial.read();
    if (a == 's')  {
      DHT.read11(dht_dpin);
      Serial.print(DHT.humidity);//humidity
      Serial.print(" ");
      Td = DHT.temperature - ((100 - DHT.humidity) / 5);
      light=analogRead(0);
      Serial.print(light);//raw data for light
      Serial.print(" ");
      Serial.print(DHT.temperature);//temperature
      Serial.print(" ");
      double temp1 = (17.269 * Td / (Td + 273.3));
      double temp2 = (17.269 * DHT.temperature / (DHT.temperature + 273.3));
      THI = (double)DHT.temperature - 0.55 * (1 - (exp(temp1) / exp(temp2))) * (DHT.temperature - 14);
      Serial.print(THI);//thi
      Serial.print(" ");
      Serial.print(people);//people number
      Serial.print(" ");
      Serial.print(door_state);//door_state //0:close 1:open
      Serial.println("");
    }
    if (a == 'a') {
      //Serial.println("turn on");
      fill_buffer(0);
      test.sendRaw(buffer_ir, 134, 38);
    }
    if (a == 'b') {
      //Serial.println("trun off");
      fill_buffer(1);
      test.sendRaw(buffer_ir, 134, 38);
    }
    if (a == 'c') {
      fill_buffer(2);
      test.sendRaw(buffer_ir, 134, 38);
    }
    if (a == 'd') {
      fill_buffer(3);
      test.sendRaw(buffer_ir, 134, 38);
    }
    if (a == 'e') {
      fill_buffer(4);
      test.sendRaw(buffer_ir, 134, 38);
    }
    if (a == 'f') {
      fill_buffer(5);
      test.sendRaw(buffer_ir, 134, 38);
    }
    if (a == 'g') {
      fill_buffer(6);
      test.sendRaw(buffer_ir, 134, 38);
    }
    if (a == 'h') {
      fill_buffer(7);
      test.sendRaw(buffer_ir, 134, 38);
    }
    if (a == 'i') {
      fill_buffer(8);
      test.sendRaw(buffer_ir, 134, 38);
    }
    if (a == 'j') {
      fill_buffer(9);
      test.sendRaw(buffer_ir, 134, 38);
    }
    if (a == 'k') {
      fill_buffer(10);
      test.sendRaw(buffer_ir, 134, 38);
    }
     if (a == 'l') {//light front on
          myservo2.attach(7);
          delay(15);
	  myservo2.write(102);
	  delay(100);
	  myservo2.write(81); 
          delay(15);		 
	  myservo2.detach();

    }
	if (a == 'm') {//light front off
          myservo2.attach(7);
          delay(15);
	  myservo2.write(60);
	  delay(150);
	  myservo2.write(81); 		   
	  myservo2.detach();
    }
	if (a == 'o') {//light back on
          myservo1.attach(6);
          delay(15);
	  myservo1.write(102);
	  delay(150);
	  myservo1.write(73);
          delay(15);		   
	  myservo1.detach();
    }
	if (a == 'p') {//light back off
          myservo1.attach(6);
          delay(15);
	  myservo1.write(45);
	  delay(150);
	  myservo1.write(73); 		   
	  delay(15);
          myservo1.detach();
    }
    if (a == 'q') {//people=people +1
      people=people +1;
    }
    
    if (a == 'r') {//people=people -1
      people=people -1;
    }
	
	
  }

}

void fill_buffer(int a) {
  int buf_counter = 0;
  buffer_ir[0] = 5000;
  buffer_ir[1] = 8480;
  buffer_ir[2] = 3660;
  buffer_ir[3] = 2397;
  buffer_ir[4] = 592;

  for (int i = 5; i <= 66; i++) {
    if (i % 2 == 1) {
      if ( ( (ac_temp[a]) & ((0x40000000) >> (i - 5) / 2 ) ) != 0 ) {
        buffer_ir[i] = 620;
      }
      else {
        buffer_ir[i] = 1840;
      }
    }
    else {

      buffer_ir[i] = 592;

    }
  }

  buffer_ir[67] = 8480;
  buffer_ir[68] = 3660;
  buffer_ir[69] = 2397;
  buffer_ir[70] = 592;
  buffer_ir[133] = 3000;

  for (int i = 71; i <= 132; i++) {
    buffer_ir[i] = buffer_ir[i - 66];
  }
  /*for(int i=0;i<134;i++){
  	Serial.println(buffer[i]);
  }*/
}

/*void door() {
  if (millis() - door_timer > 50) {
    door_timer = millis();
    door_state = 1; //open
  }  
}*/



