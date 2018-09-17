#include<basicgf.h>
#include<advancegf.h>
void backbodyhead(int ,int);
void leftside(int ,int);
void left(int,int);
void forebodyhead(int x,int y)//范围：x+-20;y-80~y-14;
{
	FillCircle(x,y-60,20,255);
	FillCircle(x,y-56,16,65535);
	circle(x,y-56,16,0);
	FillCircle(x,y-60,2,40966);
	bar(x-16,y-48,x+16,y-20,255);
	bar(x-16,y-20,x+16,y-14,65535);
	linever(x,y-20,x,y-14,2,0);
	FillCircle(x,y-36,14,65535);
	bar(x-16,y-48,x+16,y-44,63488);
	Fillellipse(x-6,y-70,x-6,y-66,6,65535);
	Fillellipse(x+6,y-70,x+6,y-66,6,65535);
	ellipse(x+6,y-70,x+6,y-66,6,0);
	ellipse(x-6,y-70,x-6,y-66,6,0);
	semicircle_down(x+4,y-68,2,0);
	semicircle_down(x-4,y-68,2,0);
	bow(x,y-72,22,0);
	linever(x,y-58,x,y-50,1,0);
	//Horizline(x,y-270,30,0);
	//Horizline(x,y-270,-30,0);
	//Horizline(x,y-280,30,0);
	//Horizline(x,y-280,-30,0);
	//Horizline(x,y-260,30,0);
	//Horizline(x,y-260,-30,0);
	Horizline(x-8,y-40,16,0);
	semicircle_up(x,y-40,8,0);
}

void backbodyhead(int x,int y)
{
    FillCircle(x,y-60,20,255);
	bar(x-16,y-48,x+16,y-20,255);
	bar(x-16,y-20,x+16,y-14,65535);
	bar(x-16,y-48,x+16,y-44,63488);
	linever(x,y-20,x,y-14,2,0);
}

void leftside(int x,int y)
{
	FillCircle(x,y-60,20,255);
	FillCircle(x-2,y-56,16,65535);
	Fillellipse(x+2,y-60,x+2,y-56,6,65535);

	//Fillellipse(x+2,y-60,x+2,y-56,3,0);
	
	/*试试圆的眼睛*/
	//circle(x+2,y-70,7,0);
	//circle(x-8,y-70,7,0);
	Fillellipse(x+3,y-68,x+3,y-66,6,65535);              //现在要做的是把两个眼睛往中间靠拢
	Fillellipse(x-10,y-68,x-10,y-66,6,65535);
	ellipse(x+4,y-68,x+4,y-66,6,0);
	ellipse(x-10,y-68,x-10,y-66,6,0);
	FillCircle(x+4,y-66,3,0);
	FillCircle(x-10,y-66,3,0);
	FillCircle(x+4,y-66,1,65535);
	FillCircle(x-10,y-66,1,65535);
	bar(x-16,y-48,x+12,y-20,255);
	FillCircle(x-3,y-62,3,40966);
	linever(x-3,y-59,x-3,y-55,1,0);
	bar(x-16,y-44,x-2,y-24,65535);
	bar(x-16,y-48,x+12,y-44,63488);
	bar(x-16,y-20,x+12,y-14,65535);
	linever(x-5,y-20,x-5,y-14,1,0);
	bow(x-3,y-77,22,0);
}

void left(int x,int y)
{
    FillCircle(x,y-60,20,255);
	fill_bow_down(x,y-60,20,65535);
	fill_bow_left(x,y-60,20,65535);
	fill_bow_right_up(x-14,y-46,28,65535);
	Fillellipse(x-14,y-73,x-14,y-69,5,65535);
	ellipse(x-14,y-73,x-14,y-69,5,0);
	Fillellipse(x-17,y-71,x-17,y-70,1,0);
	FillCircle(x-20,y-62,3,40966);
	bar(x-16,y-48,x+16,y-44,63488);
	bar(x-16,y-44,x+16,y-14,255);
	bow(x-12,y-84,30,0);
	bar(x-16,y-44,x+4,y-36,65535);
	fill_bow_right_down(x-16,y-44,20,65535);
}

void right(int x,int y)
{
	FillCircle(x,y-60,20,255);
	fill_bow_down(x,y-60,20,65535);
	fill_bow_right(x,y-60,20,65535);
	fill_bow_left_up(x+14,y-46,28,65535);
	Fillellipse(x+14,y-73,x+14,y-69,5,65535);
	ellipse(x+14,y-73,x+14,y-69,5,0);
	Fillellipse(x+17,y-71,x+17,y-70,1,0);
	FillCircle(x+20,y-62,3,40966);
	bar(x-16,y-48,x+16,y-44,63488);
	bar(x-16,y-44,x+16,y-14,255);
	bow(x+12,y-84,30,0);
	bar(x-4,y-44,x+16,y-36,65535);
	fill_bow_left_down(x+16,y-44,20,65535);
}