#include"main.h"
void enter_page();
int enterpage();
void load_page()
{
	   bar(0,0,1024,768,64049);
       bar_round_with_shadow(500,200,200,30,5,1,65535);
       bar_round_with_shadow(500,300,200,30,5,1,65535);
	   fdhz(320,200,1,1,"ÕË",0);
	   fdhz(340,200,1,1,"ºÅ",0);
	   fdhz(320,300,1,1,"ÃÜ",0);
	   fdhz(340,300,1,1,"Âë",0);
	   bar_round(300,500,200,150,20,1,31694);
	   bar_round(700,500,200,150,20,1,31694);
       fdhz(240,470,3,3,"µÇ",0);
	   fdhz(320,470,3,3,"Â¼",0);
	   fdhz(640,470,3,3,"×¢",0);
	   fdhz(720,470,3,3,"²á",0);
}



void zhuce_page()
{
	bar(0,0,1024,768,64049);
	fdhz(350,80,2,3,"×¢",0);
	fdhz(600,80,2,3,"²á",0);
	bar_round_with_shadow(500,200,200,30,5,1,65535);
    bar_round_with_shadow(500,300,200,30,5,1,65535);
    bar_round_with_shadow(500,400,200,30,5,1,65535);
	bar_round_with_shadow(500,500,200,30,5,1,65535);
    bar_round_with_shadow(500,600,200,30,5,1,65535);
	bar_round_with_shadow(500,700,100,50,5,1,255);
	fdhz(320,200,1,1,"ÕË",0);
	fdhz(340,200,1,1,"ºÅ",0);
	fdhz(320,300,1,1,"ÃÜ",0);
	fdhz(340,300,1,1,"Âë",0);
	fdhz(460,680,2,2,"Íê",0);
	fdhz(510,680,2,2,"³É",0);
}


int enterpage()
{
	   int button=0,x=0,y=0,error=0,zhuce=0;
	   unsigned int *mousesave;
	   init();
	   load_page();
       //	bar_round(500,300,200,30,5,1,31694);
	   //get_image(x,y,x+10,y+16,mousesave);
	   while(1)
	   {
		movemouse(&x,&y,&button,mousesave);
		if(x>=200&&x<=400&&y<=575&&y>=425&&button)
		{
			error_box(400,400);
			error=1;
		}

		if(x>=372&&x<=462&&y>=450&&y<=490&&button&&error==1)
		{
			load_page();
			reset_mouse(&x,&y,mousesave);
			error=0;
			return 0;
		}
			
		if(x>=600&&x<=800&&y>=425&&y<=575&&button)
		{
			zhuce_page();
			reset_mouse(&x,&y,mousesave);
			zhuce=1;
		}
		if(x>=450&&x<=550&&y>=675&&y<=725&&button&&zhuce==1)
		{
			zhuce=0;
			return 1;
		}

	   }

}