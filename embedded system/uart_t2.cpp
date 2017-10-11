#include<stdio.h>
#include <fcntl.h>
#include<iostream>
#include <unistd.h>
#include <termios.h>
#include<stdlib.h>
#include<sys/ioctl.h>
using namespace std;
int main (){
	struct termios toptions;
	int fd;
	fd = open("/dev/ttyS2", O_RDWR | O_NOCTTY);
	speed_t brate = 9600;
	cfsetispeed(&toptions, brate);
	cfsetospeed(&toptions, brate);
	while(1){
	char buf[2];
	int i =read(fd,buf,1);
	if(i>0)
		cout<<buf<<endl;
	}
	close(fd);
}
