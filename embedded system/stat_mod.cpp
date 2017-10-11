#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include<stdlib.h>
#include<sys/ioctl.h>
#include<string>

using namespace std;

int main()
{
	struct termios toptions;
	int fd;
	fd = open("/dev/ttyS2", O_RDWR | O_NOCTTY);
	speed_t brate = 9600;
	cfsetispeed(&toptions, brate);
	cfsetospeed(&toptions, brate);
	write(fd,"s",1);


	//cout << "Command sent!" << endl;
	cout << "Content-Type: text/html;\n\n";
	cout << "<html>";
	cout << "<head><meta http-equiv=content-language content=en /><meta http-equiv=content-type content=text/html; charset=utf-8 /><meta name=viewport content=width=device-width, initial-scale=1.0, maximum-scale=1.0, user-scalable=no /><meta name=apple-mobile-web-app-capable content=yes /><meta name=apple-mobile-web-app-status-bar-style content=black /><link rel=apple-touch-icon href=images/icon.png /><link rel=apple-touch-startup-image href=images/splash.png><link rel=stylesheet media=screen type=text/css href=css/reset.css />	<link rel=stylesheet media=screen type=text/css href=css/main.css /><script type=\"text/javascript\" src=\"js/jquery.js\"></script><script type=\"text/javascript src=\"js/jquery.flot.js\"></script><script type=\"text/javascript\" src=\"js/main.js\"></script><title>宿舍狀態</title></head>";
    string tmp;
	while(1)
	{

		char buf[1];
		int i =read(fd,buf,1);
		//cout<<i<<endl;
		//cout<<buf[0];
		
		if(i>0)
		{
			
		tmp=tmp+ buf[0];
	

		}

		if(buf[0]=='\n'){
			break;
		}
		
	}
	//cout<<tmp<<endl;
	string a[6];
	int l = 0;
	for (int i=0;i<sizeof(tmp)*8;i++)
	{
		if (tmp[i]==' ' ||tmp[i] == '\n')
		{
			l++;
		}
		else
		{
			a[l]+=tmp[i];
		}
	}
	/*cout << a[0] << endl;
	cout << a[1] << endl;
	cout << a[2] << endl;
	cout << a[3] << endl;*/
	cout << "<div id=wrapper><div id=header><h1 id= logo >宿舍狀態</h1>";
	cout << "<p class=header-button><a href=index.html onclick=return link(this)>Home</a></p>";
	cout << "</div>";
	cout << "<div id= content ><div class= content-box ><table class= stats ><tr><th>濕度</th><th>電燈狀態</th><th>溫度</th><th>舒適度</th><th>人數</th><th>門</th>";
	cout << "</tr><tr><td>";
	cout << a[0] << "%";
	cout << "</td><td>";
	int v = atoi(a[1].c_str());
	if (v <= 590)
	{
		cout << "燈全開";
	}
	else if (v > 590 && v <= 682)
	{
		cout << "前燈開";
	}
	else if (v > 682 && v <= 853)
	{
		cout << "後燈開";
	}
	else if (v > 853 )
	{
		cout << "全關";
	}
	//cout << v;
	cout << "</td><td>";
	cout << a[2] << "℃";
	cout << "</td><td>";
	cout << a[3];
	cout << "</td><td>";
	cout << a[4];
	cout << "人在宿舍</td><td>";
	int p = atoi(a[5].c_str());
	if (p==1)
	{
		cout << "開";
	}
	else
	{
		cout << "關";
	}
	cout << "</td></tr></table></div>";
	cout << "<div><font size = 1>";
	cout << "<div style=\"margin:0 auto;display:table;\">根據THI計算出之數值將舒適度劃分為六個等級</div>";
	cout << "<div style=\"margin:0 auto;display:table;\">指數10以下為非常寒冷</div>";
	cout << "<div style=\"margin:0 auto;display:table;\">指數11至15為寒冷</div>";
	cout << "<div style=\"margin:0 auto;display:table;\">指數16至19為稍有寒意</div>";
	cout << "<div style=\"margin:0 auto;display:table;\">指數20至26為舒適</div>";
	cout << "<div style=\"margin:0 auto;display:table;\">指數27至30為悶熱</div>";
	cout << "<div style=\"margin:0 auto;display:table;\">指數31以上為易中暑</div>";
	cout << "</font></div>";
	cout << "<div style=\"margin:0 auto;display:table;\">";
	cout << "<h2 class=t-center>其他功能</h2>";
	cout <<"<ul id= nav  class= box>";
	cout <<"<li class=ico-AC><a href=AC.cgi onclick=return link(this)>冷氣控制</a></li>";
	cout << "<li class=ico-light><a href=light.cgi onclick=return link(this)>電燈控制</a></li>";
	cout << "<li class=ico-people><a href=people.cgi onclick=return link(this)>人數控管</a></li>";
	cout <<"</div></div></html>";
	close(fd);
}
	
