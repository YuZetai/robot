#include"main.h"
#include<stdio.h>

#include"svgahead.h"
#include<conio.h>
#include"advancegf.h"
#include"hanzi.h"
#include"flame.h"
#include"module_box.h"

extern void forebodyhead(int x,int y);
extern void backbodyhead(int x,int y);
extern void left(int,int);
extern void right(int,int);

int main()
{
	int goin;
	
	//int error;
	SetSVGA64k();
	
	//input_box(700,600);
	
	
	
	
	goin = enterpage();
    if(goin==0)
	{
		printf("good!");
	}
	else
	{
		goin = enterpage();
	}
	/*
	moveaim(100,100);
	getch();*/
	//backbodyhead(500,200);



	//Putbmp64k(0,0,"c:\\cph\\robot\\garden.bmp");
	//forebodyhead(100,100);
    //right(500,200);
	//left(500,600);
	/*showHanZiBySize(100,100,"��",0,0,3);
	showHanZiBySize(600,100,"��",0,0,3);
	init();
	
	while(1)
	{
		/*if(NULL==(mousesave=(unsigned int*)malloc(160*sizeof(unsigned int))))        //为鼠标背景分配储存空�?
	    {
		    printf("there is no place") ;
		    exit(1);
	    }  
		else
		{
			if(init()==0)                                            //初始化鼠�?
	        {
		        printf("the mouse driver absense");
		        delay(5000);
		        exit(1);
	        }*/

		/*movemouse(&x,&y,&button);
		if(x==1)
		{
			exit(0);
		}
	}	*/
	return 0;
}