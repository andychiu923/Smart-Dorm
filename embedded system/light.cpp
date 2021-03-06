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
	cout << "<title>電燈控制</title>";
	cout << "</head>";
	
	cout << "<body onorientationchange=Orientation();>";
	cout << "<div id=wrapper>";
	cout << "<div id=header>";
	cout << "<h1 id=logo>電燈控制介面</h1>";
	cout << "<p class=header-button><a href=index.html onclick=return link(this)>Home</a></p>";
	cout << "</div>";
	
	cout << "<div id=content>";
	cout << "<table class=air-box>";
	cout << "<tr>";
	cout << "<td>";
	cout << "<div style=\"margin:20px auto 20px auto;display:table;\"><font size=5 color=white >前燈開關</font></div>";
	cout << "</td>";
	cout << "</tr>";
	cout << "<tr>";
	cout << "<td align=center class=air-td>";
	cout << "<a href=front_on.cgi onclick=return link(this)><img src=images/on.png></a>";
	cout << "<font color=#aa0>On</font>";
	cout << "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;";
	cout << "<a href=front_off.cgi onclick=return link(this)><img src=images/off.png></a>";
	cout << "<font color=red>Off</font>";
	cout << "</td>";
	cout << "</tr>";
	cout << "<tr>";
	cout << "<td>";
	cout << "<div style=\"margin:20px auto 20px auto;display:table;\"><font size=5 color=white >後燈開關</font></div>";
	cout << "</td>";
	cout << "</tr>";
	cout << "<tr>";
	cout << "<td align=center class=air-td>";
	cout << "<a href=back_on.cgi onclick=return link(this)><img src=images/on.png></a>";
	cout << "<font color=#aa0>On</font>";
	cout << "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;";
	cout << "<a href=back_off.cgi onclick=return link(this)><img src=images/off.png></a>";
	cout << "<font color=red>Off</font>";
	cout << "</td>";
	cout << "</tr>";
	cout << "</table>";
	cout << "<div style=\"margin:0 auto;display:table;\">";
	cout << "<h2 class=t-center>其他功能</h2>";
	cout << "<ul id= nav  class= box>";
	cout << "<li class=ico-AC><a href=AC.cgi onclick=return link(this)>冷氣控制</a></li>";
	cout << "<li class=ico-stats><a href=stats.cgi onclick=return link(this)>宿舍狀態</a></li>";
	cout << "<li class=ico-people><a href=people.cgi onclick=return link(this)>人數控管</a></li>";
	cout << "</div></div></html>";
}
	