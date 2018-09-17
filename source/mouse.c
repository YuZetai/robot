/***********************************************/
/*在dos.h中REGS的定义如下：
	struct WORDREGS
	{
		unsigned int ax, bx, cx, dx, si, di, cflag, flags;
	};

	struct BYTEREGS
	{
		unsigned char al, ah, bl, bh, cl, ch, dl, dh;
	};

	union REGS
	{
		struct WORDREGS x;
		struct BYTEREGS h;
	};
**************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<dos.h>
#include"SVGAhead.h"
#define xmax 1023
#define xmin 1
#define ymax 767
#define ymin 1//这个是鼠标移动范围
#include"mouse.h"
union REGS regs;

void movemouse(int *mx,int *my,int *mbutt,unsigned int *mousesave);
int init();
int getfun(int *mx,int *my,int *mbutt);
void drawmouse(int x,int y)//画出鼠标
{
	int i,j;
	//color;
    int cu[16][10]={
	{1, 1, 3, 3, 3, 3, 3, 3, 3, 3},
	{1, 2, 1, 3, 3, 3, 3, 3, 3, 3},
	{1, 2, 2, 1, 3, 3, 3, 3, 3, 3},
	{1, 2, 2, 2, 1, 3, 3, 3, 3, 3},
	{1, 2, 2, 2, 2, 1, 3, 3, 3, 3},
	{1, 2, 2, 2, 2, 2, 1, 3, 3, 3},
	{1, 2, 2, 2, 2, 2, 2, 1, 3, 3},
	{1, 2, 2, 2, 2, 2, 2, 2, 1, 3},
	{1, 2, 2, 2, 2, 2, 2, 2, 2, 1},
	{1, 2, 2, 2, 2, 2, 2, 1, 3, 3},
	{1, 2, 2, 2, 2, 2, 1, 3, 3, 3},
	{1, 2, 1, 3, 1, 2, 2, 1, 3, 3},
	{1, 1, 3, 3, 1, 2, 2, 1, 3, 3},
	{3, 3, 3, 3, 3, 1, 2, 2, 1, 3},
	{3, 3, 3, 3, 3, 1, 2, 2, 1, 3},
	{3, 3, 3, 3, 3, 3, 1, 2, 2, 1}
};
	/*{{2,0,0,0,0,0,0,0,0,0},//把鼠标形状存在一个数组内
					{2,2,0,0,0,0,0,0,0,0},
					{2,1,2,0,0,0,0,0,0,0},
					{2,1,1,2,0,0,0,0,0,0},
					{2,1,1,1,2,0,0,0,0,0},
					{2,1,1,1,1,2,0,0,0,0},
					{2,1,1,1,1,1,2,0,0,0},
					{2,1,1,1,1,1,1,2,0,0},
					{2,1,1,1,1,1,1,1,2,0},
					{2,1,1,1,1,1,2,2,2,2},
					{2,1,1,2,1,1,2,0,0,0},
					{2,1,2,0,2,1,2,0,0,0},
					{2,2,0,0,0,2,1,2,0,0},
					{2,0,0,0,0,0,2,2,0,0},
					{0,0,0,0,0,0,0,0,0,0}};
   */
	
	for(i=0;i<16;i++)
	{
		for(j=0;j<10;j++)
		{
			if(cu[i][j]==1)
			{
			//color=(x+j,y+i);
			Putpixel64k(x+j,y+i,0);
			}
			if(cu[i][j]==2)
			{
				Putpixel64k(x+j,y+i,0xffff);
			}
		}
	}
}



int init()//初始化鼠标
{
	int retcode;//用来判断鼠标设置是否成功
	regs.x.ax = 0;
	/*这里，regs为一个联合，用来定义16位寄存器。这个联合下有两个结构，x可以访问或设置寄存器，h可以访问寄存器，区别大概就是只读和
	可读可写的区别。80x86中的16位通用寄存器有:ax,bx,cx,dx,si,di,sp,bp(最后两个c语言里面不会出现)，鼠标里面用到的主要是ax,bx,cx,dx.
	这里我们先把一个ax置为0，然后在int86函数中会用到。*/
	int86(51,&regs,&regs);
	/*这个函数是设置中断函数，就是设置完之后，如果符合中断条件就会产生一些效果。第一个参数是中断方式，也就是效果。这里我们要用到的鼠
	标中断的代号是33H，也就是51。第二个是输入的参数，第三个是输出的参数，在这里我们都用regs,发生中断的时候就会把regs里的寄存器数据输入
	，然后改变寄存器的值并输出来。当我们用不同的输入参数时就可以产生不同的功能，在这里，ax=0是初始化功能，输出结果为：ax=0表示不支持
	鼠标，ax=ffff支持。*/
	retcode = regs.x.ax;
	if(retcode==0)
	{
		return 0;//调用这个函数的时候做一下判断，返回0的话证明初始化不成功。
	}
	
	//接下来，ax=7代表设置水平移动的范围，8代表竖直范围,范围值用cx,dx来设置。
	regs.x.ax = 7;
	regs.x.cx = xmin;
	regs.x.dx = xmax;
	int86(51,&regs,&regs);
	regs.x.ax = 8;
	regs.x.cx = ymin;
	regs.x.dx = ymax;
	int86(51,&regs,&regs);
	
	
	return retcode;
	
}


int getfun(int *mx,int *my,int *mbutt)//用于读取鼠标位置信息和按键情况
{
	int xx0=*mx,yy0=*my,buto=0;
	int xnew,ynew;
	
	do{
		regs.x.ax=3;//3代表读取鼠标位置信息和按键情况，输出：bx=按键状态,位0=1--左键，
		//1=1--右键，2=1--中键；cx=水平位置，dx=垂直位置。
		int86(51,&regs,&regs);
		xnew = regs.x.cx;
		ynew = regs.x.dx;
		*mbutt = regs.x.bx;
	}while(xnew==xx0&&ynew==yy0&&*mbutt==buto);//如果鼠标状态不变就一直调用循环获取鼠标情况，直到发生改变。
	
	
	*mx = xnew;
	*my = ynew;
	
	return 0;
}


void movemouse(int *mx,int *my,int *mbutt,unsigned int *mousesave)
{
   int xm,ym;
   int xx0=*mx;
   int yy0=*my;
   //static int first_click=0;//用于使行158的操作只做一次
   /*
   if(first_click==0)
   {
	   get_image(0,0,10,16,mousesave);
	   first_click=1;
   }*/
   
   getfun(&xm,&ym,mbutt);
   
   put_image(xx0,yy0,xx0+10,yy0+16,mousesave);
   get_image(xm,ym,xm+10,ym+16,mousesave);
   
   
   drawmouse(xm,ym);
   
   *mx=xm;
   *my=ym;
}

void reset_mouse(int *x,int *y,unsigned int *mousesave)
{
	get_image(1,1,11,17,mousesave);
	*x=1;
	*y=1;
	movemouse(x,y,0,mousesave);
}