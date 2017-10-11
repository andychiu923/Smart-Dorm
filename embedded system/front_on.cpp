#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include<stdlib.h>
#include<sys/ioctl.h>
#include<string.h>
#include<stdio.h>

using namespace std;

int main()
{
	struct termios toptions;
	int fd;
	fd = open("/dev/ttyS2", O_RDWR | O_NOCTTY);
	speed_t brate = 9600;
	cfsetispeed(&toptions, brate);
	cfsetospeed(&toptions, brate);
	cout << "Content-Type: text/html;\n\n";
	write(fd,"l",1);
	cout << "<head>";
	cout << "<meta http-equiv=content-language content=en />";
	cout << "<meta http-equiv=content-type content=text/html; charset=utf-8 />";
	cout << "<meta name=viewport content=width=device-width, initial-scale=1.0, maximum-scale=1.0, user-scalable=no />";
	cout << "<meta name=apple-mobile-web-app-capable content=yes />";
	cout << "<meta name=apple-mobile-web-app-status-bar-style content=black />";
	cout << "<link rel=apple-touch-icon href=images/icon.png />";
	cout << "<link rel=apple-touch-startup-image href=images/splash.png>";
	cout << "<link rel=stylesheet media=screen type=text/css href=css/reset.css />	";
	cout << "<link rel=stylesheet media=screen type=text/css href=css/main.css />";
	cout << "<script type=text/javascript src=js/jquery.js></script>";
	cout << "<script type=text/javascript src=js/jquery.flot.js></script>	";
	cout << "<script type=text/javascript src=js/main.js></script>";
	cout << "<title>冷氣控制</title>";
	cout << "</head>";
	cout << "<body onorientationchange=Orientation();>";
	cout << "<div id=wrapper>";
	cout << "<div id=header>";
	cout << "<h1 id=logo>電燈控制</h1>";
	cout << "<p class=header-button left><a href=javascript:history.go(-1) onclick=return link(this)>Back</a></p>";
	cout << "</div>";
	cout << "<div style=\"margin:200px auto 200px auto ;display:table;\"><b><font size = 8>前燈已打開!</font></b></div>";
	cout << "</div>";
	close(fd);
}