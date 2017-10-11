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
	cout << "Content-Type: text/html;\n\n";
	cout << "<html>";
	cout << "<head>";
	cout << "<meta http-equiv=content-language content=en />";
	cout << "<meta http-equiv=content-type content=text/html; charset=utf-8 />";
	cout << "<meta name=viewport content=width=device-width, initial-scale=1.0, maximum-scale=1.0, user-scalable=no />";
	cout << "<meta name=apple-mobile-web-app-capable content=yes />";
	cout << "<meta name=apple-mobile-web-app-status-bar-style content=black />";
	cout << "<link rel=apple-touch-icon href=images/icon.png />";
	cout << "<link rel=apple-touch-startup-image href=images/splash.png>";
	cout << "<link rel=stylesheet media=screen type=text/css href=css/reset.css />";
	cout << "<link rel=stylesheet media=screen type=text/css href=css/main.css />";
	cout << "<link rel=shortcut icon href=home.ico/>";
	cout << "<script type=text/javascript src=js/jquery.js></script>";
	cout << "<script type=text/javascript src=js/jquery.flot.js></script>";
    cout << "<script type=text/javascript src=js/main.js></script>"	;
	cout << "<title>冷氣控制</title>";
	cout << "</head>";
	
	cout << "<body onorientationchange=Orientation();>";
	cout << "<div id=wrapper>";
	cout << "<div id=header>";
	cout << "<h1 id=logo>冷氣控制介面</h1>";
	cout << "<p class=header-button><a href=index.html onclick=return link(this)>Home</a></p>";
	cout << "</div>";
	
	cout << "<div id=content>";
	cout << "<h2 class=t-center>開關</h2>";
	cout << "<table class=air-box>";
	cout << "<tr>";
	cout << "<td align=center class=air-td>";
	cout << "<a href=turn_on.cgi onclick=return link(this)><img src=images/on.png></a>";
	cout << "<font color=#aa0>On</font>";
	cout << "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;";
	cout << "<a href=turn_off.cgi onclick=return link(this)><img src=images/off.png></a>";
	cout << "<font color=red>Off</font>";
	cout << "</td>";
	cout << "</tr>";
	cout << "</table>";
	cout << "<form action=AC.cgi style=\"margin:20px auto 20px auto;display:table;\">";
	cout << "<div><label>Please Enter the Temperature:  <input name=e size=10></label></div>";
	cout << "<div style=\"margin:0 auto;display:table;\">(range:20~28)</div>";
	cout << "<div style=\"margin:20px auto 20px auto;display:table;\"><input type=submit value=Submit></div>";
	cout << "</form>";
	char* a = getenv("QUERY_STRING");
	int v = 0;
	struct termios toptions;
	int fd;
	fd = open("/dev/ttyS2", O_RDWR | O_NOCTTY);
	speed_t brate = 9600;
	cfsetispeed(&toptions, brate);
	cfsetospeed(&toptions, brate);
    /*if (a == NULL)
    {
		cout<<"NO COMMAND!" ;
    }*/
	if(a == NULL)
		cout << "<P>Error! Error in passing data from form to script.";
	else if(sscanf(a,"e=%ld",&v)!=2)
		cout << " ";
	else
		cout << v;
	if (v==0)
	{
		
	}
	else if (v==20)
	{
		write(fd,"k",1);
		cout << "<div style=\"margin:20px auto 20px auto;display:table;\"><font size=8 color=blue><b>The Temperature has now been changed to 20</b></font></div>";
		close(fd);
	}
	else if (v==21)
	{
		write(fd,"j",1);
		cout << "<div style=\"margin:20px auto 20px auto;display:table;\"><font size=8 color=blue><b>The Temperature has now been changed to 21</b></font></div>";
		close(fd);
	}
	else if (v==22)
	{
		write(fd,"i",1);
		cout << "<div style=\"margin:20px auto 20px auto;display:table;\"><font size=8 color=blue><b>The Temperature has now been changed to 22</b></font></div>";
		close(fd);
	}
	else if (v==23)
	{
		write(fd,"h",1);
		cout << "<div style=\"margin:20px auto 20px auto;display:table;\"><font size=8 color=blue><b>The Temperature has now been changed to 23</b></font></div>";
		close(fd);
	}
	else if (v==24)
	{
		write(fd,"g",1);
		cout << "<div style=\"margin:20px auto 20px auto;display:table;\"><font size=8 color=blue><b>The Temperature has now been changed to 24</b></font></div>";
		close(fd);
	}
	else if (v==25)
	{
		write(fd,"f",1);
		cout << "<div style=\"margin:20px auto 20px auto;display:table;\"><font size=8 color=blue><b>The Temperature has now been changed to 25</b></font></div>";
		close(fd);
	}
	else if (v==26)
	{
		write(fd,"e",1);
		cout << "<div style=\"margin:20px auto 20px auto;display:table;\"><font size=8 color=blue><b>The Temperature has now been changed to 26</b></font></div>";
		close(fd);
	}
	else if (v==27)
	{
		write(fd,"d",1);
		cout << "<div style=\"margin:20px auto 20px auto;display:table;\"><font size=8 color=blue><b>The Temperature has now been changed to 27</b></font></div>";
		close(fd);
	}
	else if (v==28)
	{
		write(fd,"c",1);
		cout << "<div style=\"margin:20px auto 20px auto;display:table;\"><font size=8 color=blue><b>The Temperature has now been changed to 28</b></font></div>";
		close(fd);
	}
	else
	{
		cout << "<div style=\"margin:20px auto 20px auto;display:table;\"><font size=8 color=red><b>Please Enter the Temperature from 20 to 28</b></font></div>";
	}
	cout << "<h2 class=t-center>其他功能</h2>";
	cout << "<ul id=nav class=box style=\"margin:0 auto;display:table;\">";
	cout << "<li class=ico-stats><a href=stats.cgi onclick=return link(this)>宿舍狀態</a></li>";
	cout << "<li class=ico-light><a href=light.cgi onclick=return link(this)>電燈控制</a></li>";
	cout << "<li class=ico-people><a href=people.cgi onclick=return link(this)>人數控管</a></li>";
	cout << "</ul>";
	cout << "</div>";
}