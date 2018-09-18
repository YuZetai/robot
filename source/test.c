#include"main.h"



void main()
{
	int goin;
	ROBOT_CASE robot_position;

	SetSVGA64k();
	robot_position.x = 100;
	robot_position.y = 100;
	//input_box(700,600);
	
	/*
	
	
	goin = enterpage();
    if(goin==0)
	{
		printf("good!");
	}
	else
	{
		delay0(10000);
		goin = enterpage();
	}
	
	*/
	
	
	
	
    //forebodyhead(robot_position);
	movedown(&robot_position);
	moveright(&robot_position);
	getch();
}