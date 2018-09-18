#include"main.h"

void forebodyhead(ROBOT_CASE robot_position)//范围：robot_position.x+-20;robot_position.y-80~robot_position.y-14;
{
	FillCircle(robot_position.x,robot_position.y-60,20,255);
	FillCircle(robot_position.x,robot_position.y-56,16,65535);
	circle(robot_position.x,robot_position.y-56,16,0);
	FillCircle(robot_position.x,robot_position.y-60,2,40966);
	bar(robot_position.x-16,robot_position.y-48,robot_position.x+16,robot_position.y-20,255);
	bar(robot_position.x-17,robot_position.y-21+robot_position.leg_left,robot_position.x,robot_position.y-13+robot_position.leg_left,0);
	bar(robot_position.x,robot_position.y-21+robot_position.leg_right,robot_position.x+17,robot_position.y-13+robot_position.leg_right,0);
	bar(robot_position.x-16,robot_position.y-20+robot_position.leg_left,robot_position.x-1,robot_position.y-14+robot_position.leg_left,65535);
	bar(robot_position.x+1,robot_position.y-20+robot_position.leg_right,robot_position.x+16,robot_position.y-14+robot_position.leg_right,65535);
	FillCircle(robot_position.x,robot_position.y-36,14,65535);
	bar(robot_position.x-16,robot_position.y-48,robot_position.x+16,robot_position.y-44,63488);
	Fillellipse(robot_position.x-6,robot_position.y-70,robot_position.x-6,robot_position.y-66,6,65535);
	Fillellipse(robot_position.x+6,robot_position.y-70,robot_position.x+6,robot_position.y-66,6,65535);
	ellipse(robot_position.x+6,robot_position.y-70,robot_position.x+6,robot_position.y-66,6,0);
	ellipse(robot_position.x-6,robot_position.y-70,robot_position.x-6,robot_position.y-66,6,0);
	semicircle_down(robot_position.x+4,robot_position.y-68,2,0);
	semicircle_down(robot_position.x-4,robot_position.y-68,2,0);
	bow(robot_position.x,robot_position.y-72,22,0);
	linever(robot_position.x,robot_position.y-58,robot_position.x,robot_position.y-50,1,0);

	Horizline(robot_position.x-8,robot_position.y-40,16,0);
	semicircle_up(robot_position.x,robot_position.y-40,8,0);
}

void backbodyhead(ROBOT_CASE robot_position)//范围：x+-20,y-80~y-14;
{
    FillCircle(robot_position.x,robot_position.y-60,20,255);
	bar(robot_position.x-16,robot_position.y-48,robot_position.x+16,robot_position.y-20,255);
	bar(robot_position.x-16,robot_position.y-20+robot_position.leg_left,robot_position.x,robot_position.y-14+robot_position.leg_left,65535);
	bar(robot_position.x,robot_position.y-20+robot_position.leg_right,robot_position.x+16,robot_position.y-14+robot_position.leg_right,65535);
	bar(robot_position.x-16,robot_position.y-48,robot_position.x+16,robot_position.y-44,63488);
	linever(robot_position.x,robot_position.y-20,robot_position.x,robot_position.y-14,2,0);
}



/*此函数由于太丑，已经废弃，请不要尝试运行，否则瞎了后果自负*/
void leftside(ROBOT_CASE robot_position)
{
	FillCircle(robot_position.x,robot_position.y-60,20,255);
	FillCircle(robot_position.x-2,robot_position.y-56,16,65535);
	Fillellipse(robot_position.x+2,robot_position.y-60,robot_position.x+2,robot_position.y-56,6,65535);
	Fillellipse(robot_position.x+3,robot_position.y-68,robot_position.x+3,robot_position.y-66,6,65535);              //现在要做的是把两个眼睛往中间靠拢
	Fillellipse(robot_position.x-10,robot_position.y-68,robot_position.x-10,robot_position.y-66,6,65535);
	ellipse(robot_position.x+4,robot_position.y-68,robot_position.x+4,robot_position.y-66,6,0);
	ellipse(robot_position.x-10,robot_position.y-68,robot_position.x-10,robot_position.y-66,6,0);
	FillCircle(robot_position.x+4,robot_position.y-66,3,0);
	FillCircle(robot_position.x-10,robot_position.y-66,3,0);
	FillCircle(robot_position.x+4,robot_position.y-66,1,65535);
	FillCircle(robot_position.x-10,robot_position.y-66,1,65535);
	bar(robot_position.x-16,robot_position.y-48,robot_position.x+12,robot_position.y-20,255);
	FillCircle(robot_position.x-3,robot_position.y-62,3,40966);
	linever(robot_position.x-3,robot_position.y-59,robot_position.x-3,robot_position.y-55,1,0);
	bar(robot_position.x-16,robot_position.y-44,robot_position.x-2,robot_position.y-24,65535);
	bar(robot_position.x-16,robot_position.y-48,robot_position.x+12,robot_position.y-44,63488);
	bar(robot_position.x-16,robot_position.y-20,robot_position.x+12,robot_position.y-14,65535);
	linever(robot_position.x-5,robot_position.y-20,robot_position.x-5,robot_position.y-14,1,0);
	bow(robot_position.x-3,robot_position.y-77,22,0);
	//fill_bow_left_down(robot_position.x-3,robot_position.y-57,8,63666);
	//fill_bow_right_down(robot_position.x-3,robot_position.y-57,8,63666);
	fill_bow_left_down(robot_position.x-3,robot_position.y-57,8,63897);
	fill_bow_right_down(robot_position.x-3,robot_position.y-57,8,63897);
}

void left(ROBOT_CASE robot_position)//x-23~x+20,y-80~y-9
{
    FillCircle(robot_position.x,robot_position.y-60,20,255);
	fill_bow_down(robot_position.x,robot_position.y-60,20,65535);
	fill_bow_left(robot_position.x,robot_position.y-60,20,65535);
	fill_bow_right_up(robot_position.x-14,robot_position.y-46,28,65535);
	Fillellipse(robot_position.x-14,robot_position.y-73,robot_position.x-14,robot_position.y-69,5,65535);
	ellipse(robot_position.x-14,robot_position.y-73,robot_position.x-14,robot_position.y-69,5,0);
	Fillellipse(robot_position.x-17,robot_position.y-71,robot_position.x-17,robot_position.y-70,1,0);
	FillCircle(robot_position.x-20,robot_position.y-62,3,40966);
	bar(robot_position.x-16,robot_position.y-48,robot_position.x+16,robot_position.y-44,63488);
	bar(robot_position.x-15,robot_position.y-15+robot_position.leg_left,robot_position.x+15,robot_position.y-9+robot_position.leg_left,0);
	bar(robot_position.x-14,robot_position.y-14+robot_position.leg_left,robot_position.x+14,robot_position.y-10+robot_position.leg_left,65535);
	bar(robot_position.x-16,robot_position.y-44,robot_position.x+16,robot_position.y-14,255);
	bow(robot_position.x-12,robot_position.y-84,30,0);
	bar(robot_position.x-16,robot_position.y-44,robot_position.x+4,robot_position.y-36,65535);
	fill_bow_right_down(robot_position.x-16,robot_position.y-44,20,65535);
	bar(robot_position.x-15,robot_position.y-15+robot_position.leg_right,robot_position.x+15,robot_position.y-9+robot_position.leg_right,0);
	bar(robot_position.x-14,robot_position.y-14+robot_position.leg_right,robot_position.x+14,robot_position.y-10+robot_position.leg_right,65535);
}

void right(ROBOT_CASE robot_position)//x-20~x+26,y-80~y-5
{
	FillCircle(robot_position.x,robot_position.y-60,20,255);
	fill_bow_down(robot_position.x,robot_position.y-60,20,65535);
	fill_bow_right(robot_position.x,robot_position.y-60,20,65535);
	fill_bow_left_up(robot_position.x+14,robot_position.y-46,28,65535);
	Fillellipse(robot_position.x+14,robot_position.y-73,robot_position.x+14,robot_position.y-69,5,65535);
	ellipse(robot_position.x+14,robot_position.y-73,robot_position.x+14,robot_position.y-69,5,0);
	Fillellipse(robot_position.x+17,robot_position.y-71,robot_position.x+17,robot_position.y-70,1,0);
	FillCircle(robot_position.x+20,robot_position.y-62,3,40966);
	bar(robot_position.x,robot_position.y-16+robot_position.leg_right,robot_position.x+26,robot_position.y-6+robot_position.leg_right,0);
	bar(robot_position.x+1,robot_position.y-15+robot_position.leg_right,robot_position.x+24,robot_position.y-7+robot_position.leg_right,65535);
	bar(robot_position.x-16,robot_position.y-44,robot_position.x+16,robot_position.y-14,255);
	bow(robot_position.x+12,robot_position.y-84,30,0);
	bar(robot_position.x-15,robot_position.y-15+robot_position.leg_left,robot_position.x+11,robot_position.y-5+robot_position.leg_left,0);
	bar(robot_position.x-14,robot_position.y-14+robot_position.leg_left,robot_position.x+10,robot_position.y-6+robot_position.leg_left,65535);
	fill_bow_left_down(robot_position.x+16,robot_position.y-44,20,65535);
	bar(robot_position.x-16,robot_position.y-44,robot_position.x+18,robot_position.y-40,63488);
}