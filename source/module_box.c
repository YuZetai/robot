#include"advancegf.h"
#include<svgahead.h>
#include"basicgf.h"
#include"hzxs.h"
void error_box(int x,int y)
{

	bar(x-350,y-100,x+350,y-70,255);
	bar(x-350,y-70,x+350,y+100,46651);
	bar_round(x+335,y-85,28,28,2,1,63488);
	bar_round(x+12,y+70,100,40,10,2,31694);
	lean_line_thick(x+335,y-102,25,45,5,65535);
	lean_line_thick(x+334,y-69,25,-45,5,65535);
	fdhz(x-75,y+10,2,2,"内",0);
	fdhz(x-30,y+10,2,2,"存",0);
	fdhz(x+15,y+10,2,2,"溢",0);
	fdhz(x+60,y+10,2,2,"出",0);
	//fdhz(x+30,y+10,2,2,"!",0);
	fdhz(x-25,y+53,2,2,"确",0);
	fdhz(x+25,y+53,2,2,"定",0);
}

void input_box(int x,int y)
{
	bar_round_with_shadow(x,y,300,180,5,3,65535);
	bar_round(x+115,y+75,70,30,2,1,2048-255);
}

void phone_module(int x,int y)
{
	bar_round_with_shadow(x,y,120,120,30,1,1788);
}

void phone_back(int x,int y)
{
	FillCircle(x,y,40,65535);
    circle(x,y,35,0);
	circle(x,y,40,0);
}