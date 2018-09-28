#include"main.h"







void load_page()
{
	   bar(0,0,1024,768,1503);
	   FillCircle(200,150,80,34429);
	   FillCircle(700,300,200,34431);
       bar_round_with_shadow(500,200,400,50,5,1,65535);
       bar_round_with_shadow(500,350,400,50,5,1,65535);
	   fdhz(250,190,1,1,"ÕÊ",0);
	   fdhz(270,190,1,1,"ºÅ",0);
	   fdhz(250,340,1,1,"ÃÜ",0);
	   fdhz(270,340,1,1,"Âë",0);
	   bar_round(300,600,200,150,20,1,31694);
	   bar_round(700,600,200,150,20,1,31694);
       fdhz(240,570,3,3,"µÇ",0);
	   fdhz(320,570,3,3,"Â¼",0);
	   fdhz(640,570,3,3,"×¢",0);
	   fdhz(720,570,3,3,"²á",0);
}



void zhuce_page()
{
	bar(0,0,1024,768,1503);
	fdhz(370,80,2,3,"×¢",0);
	fdhz(600,80,2,3,"²á",0);
	bar_round_with_shadow(500,200,200,30,5,1,65535);
    bar_round_with_shadow(500,300,200,30,5,1,65535);
    bar_round_with_shadow(500,400,200,30,5,1,65535);
	bar_round_with_shadow(500,500,200,30,5,1,65535);
    bar_round_with_shadow(500,600,200,30,5,1,65535);
	bar_round_with_shadow(500,700,100,50,5,1,255);
	fdhz(320,200,1,1,"ÕÊ",0);
	fdhz(340,200,1,1,"ºÅ",0);
	fdhz(320,300,1,1,"ÃÜ",0);
	fdhz(340,300,1,1,"Âë",0);
	fdhz(460,680,2,2,"Íê",0);
	fdhz(510,680,2,2,"³É",0);
}


int enterpage()
{
	char *accounts='\0',*code='\0';
	int temp,error=0;
	int buttons,x,y,judge;
	LOADING load1;
    load1.sign = 0;
    load1.sign_up_case=2;
    load1.sign_box=2;
	mouseInit(&x, &y,&buttons);
	load_page();
    while(1)

	{
		newxy(&x, &y, &buttons);
				    /*³õÊ¼»¯£¬½ÓÊÜ»º³åÇøÊý¾Ý*/
		
		if (kbhit() != 0)
		{
			temp = bioskey(0);
		}

		
		
		
		
		
		
		
		
		if(x>=200&&x<=400&&y<=675&&y>=525&&buttons)
		{
			load1.sign_box=2;
			/*
			yanzheng
			*/
			return load1.sign_up_case;
		}
/*
		if(x>=372&&x<=462&&y>=450&&y<=490&&buttons&&error==1)
		{
			load_page();
			//reset_mouse(&x,&y,mousesave);
			error=0;
			return 0;
		}*/
			
		if(x>=600&&x<=800&&y>=525&&y<=675&&buttons)
		{
			load1.sign_box=2;
			zhuce_page();
			//reset_mouse(&x,&y,mousesave);
			load1.sign=1;
		}
		/*
		if(x>=450&&x<=550&&y>=675&&y<=725&&button&&zhuce==1)
		{
			zhuce=0;
			return 1;
		}*/
		
		
		
		
		
		
        
		if(x>=300&&x<=700&&y>=175&&y<=225&&buttons)
		{
			load1.sign_box=0;
		}
		
		if(x>=300&&x<=700&&y>=325&&y<=375&&buttons)
		{
			load1.sign_box=1;
		}
		
		if(load1.sign_box==0)//ÊäÈëid
		{
			judge = input_me(&x,&y,0,accounts,code);

		}
		if(load1.sign_box==1)//ÊäÈëpassword
		{
			judge = input_me(&x,&y,1,accounts,code);
		}
		if(judge==1)
		{
			return 1;
		}
	}
}



int mainpage()
{
	int fail;

	ROBOT_CASE robot_position;
    fail = Putbmp64k(1,1,"c:\\cph\\robot\\bgi\\second.bmp");
    if(fail==-1)
	{
		null_box(500,500);
	}
	null_box(500,500);
	robot_position.x = 100;
	robot_position.y = 100;
	movedown(&robot_position);
	moveright(&robot_position);
	
	if(getch())
	{
		return 1;
	}
	
}
