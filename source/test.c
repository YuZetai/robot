#include"main.h"



void main()
{


	
	//input_box(700,600);
	
	
	int goin=0,finish=0;
	SetSVGA64k();
	while(goin!=1)
	{
		goin = enterpage();
	}
    while(finish!=1)
    {
		finish = mainpage();
	}
	getch();

	/*
    if(goin==0)
	{
		printf("good!");
	}
	else
	{
		goin = enterpage();
	}
	
	*/
	/*
	
	int button=0,x=0,y=0,error=0,zhuce=0,panduan=0;
	unsigned int *mousesave;
	SetSVGA64k();
	init();
	phone_back(600,500);
	while(1)
	{
		if(panduan==0)
		{
			phone_back(600,500);
		}
		movemouse(&x,&y,&button,mousesave);
		if((x-600)*(x-600)+(y-500)*(y-500)<=40)
		{
			FillCircle(600,500,35,1503);
			panduan=1;
		}
		else
			panduan=0;
		if(x==1)
			break;
	}
	*/
    //moveright(&robot_position);
    
	getch();
}