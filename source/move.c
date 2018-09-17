#include<svgahead.h>
extern void forebodyhead(int x,int y);
extern void delay();
void moveaim(int x,int y)
{
	int i,x0;
	unsigned int *cat;
	get_image(x-20,y-80,x+20,y-14,cat);
	for(i=0;i<10;i++);
	{
		put_image(x-20,y-80,x+20,y-14,cat);
		x0=x+100;
		get_image(x0-20,y-80,x0+20,y-14,cat);
		forebodyhead(x0,y);
		x=x0;
		delay(1000);
		
		
	}
}
