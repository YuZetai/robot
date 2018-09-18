#include<stdio.h>
#include"svgahead.h"
  /******************************************************************
   功能说明：画水平线函数
   参数说明：x0,y0 起始坐标   x1,y1终止坐标  thick 厚度  color 颜色
   无返回值
 *******************************************************************/
  void linelevel(int x0,int y0,int x1,int y1,int thick,int color)
  {
   int i,j,k;
   if(x0>x1)                                       /*确保x0为较小的一方*/
   {
	k=x0;
	x0=x1;
	x1=k;
   }

   if(x1<=0||x1>=1024||y1<=0||y1>=768||x1>=1024)  /*确保画线在屏幕范围之内*/
	{
		printf("the line is beyond the screen!");
		return;
	}

   for(i=0;i<thick;i++)
   {
	for(j=0;j<x1-x0;j++)
	{
		Putpixel64k(x0+j,y0+i,color);
	}
   }
 }

/**************************************************************/



/***************************************************************
   功能说明：画竖线函数
   参数说明：x0,y0 起始坐标   x1,y1终止坐标  thick 厚度  color 颜色
   无返回值
***************************************************************/
void linever(int x0,int y0,int x1,int y1,int thick,int color)
  {
	int   i = 0;
	int   j = 0;
	//int   k=0;
   int high;
   high = y1 - y0;
  /* if(y0>y1)                                       确保y0为较小的一方
   {
	k=y0;
	y0=y1;
	y1=k;
   }  
   */
   if(x1<=0||x1>=1024||y1<=0||y1>=768||x1>=1024)  /*确保画线在屏幕范围之内*/
	{
		printf("the line is beyond the screen!");
		return;
	}

   for(i=0;i<thick;i++)
   {
	for(j=0;j<high;j++)
	{
		Putpixel64k(x0+i,y0+j,color);
	}
   }
 }


/**********************************************************/


/**********************************************************
Function：		Horizline

Description：	画水平线函数
可以接收超出屏幕范围的数据，只画出在屏幕内部分
因为没有防止整型变量溢出的判断，画超出屏幕的线时应防止输入特大数据

Calls：			Selectpage

Called By：		Line
Bar
Circlefill

Input：			int x					起始点横坐标，从左到右增加，0为最小值（屏幕参考系）
int y					起始点纵坐标，从上到下增加，0为最小值（屏幕参考系）
int width				水平长度，为正向右延伸，为负向左延伸
unsigned char color		颜色数，共有256种

Output：		屏幕上画出水平线

Return：		None
Others：		None
**********************************************************/
void Horizline(int x, int y, int width, int  color)
{
	/*显存指针常量，指向显存首地址，指针本身不允许修改*/
	unsigned int  far * const video_buffer = (unsigned int  far *)0xa0000000L;

	/*要切换的页面号*/
	unsigned char new_page = 0;

//	unsigned char old_page = 0;
	/*对应显存地址偏移量*/
	unsigned long int page;

	/*i是x的临时变量，后作循环变量*/
	int i;

	/*判断延伸方向，让起始点靠左*/
	if (width < 0)
	{
		x = x + width;
		width = -width;
	}

	i = x;

	/*省略超出屏幕左边部分*/
	if (x < 0)
	{
		x = 0;
		width += i;
	}

	/*整条线在屏幕外时退出*/
	if (x >= 1024)
	{
		return;
	}

	/*整条线在屏幕外时退出*/
	if (y < 0 || y >= 768)
	{
		return;
	}

	/*省略超出屏幕右边部分*/
	if (x + width > 1024)
	{
		width = 1024 - x;
	}

	/*计算显存地址偏移量和对应的页面号，做换页操作*/
	page = ((unsigned long int)y << 10) + x;
	new_page = page >> 15;
	
		SelectPage(new_page);
	


	/*向显存写入颜色，水平线画出*/
	for (i = 0; i < width; i++)
	{
		*(video_buffer + page + i) = color;
	}
}


/************************************************************
   功能说明：画水平矩形函数
   参数说明: x0,y0 左上角坐标   x1,y1右下角坐标 color 颜色
************************************************************/
void bar(int x0, int y0, int x1, int y1, int color)
{

	int i;

	int wide;                /*计算矩形的长和宽*/
	wide = x1 - x0;


	for (i = y0; i <= y1; i++)
	{
		Horizline(x0, i, wide, color);
	}
}


/**************************************************************
 功能说明：以(x,y)点为圆心，以radius为半径画圆，没有防止超出屏幕的判断，
 可以将没有超出的部分画出。
 参数说明：x,y为圆点，radius 为半径，color为颜色。
 无返回值：
 **************************************************************/
 void circle(int x0,int y0,int radius,int color)
 {
  
	int x, y, d;
	y = radius;
	d = 3 - radius << 1;
	
	for (x = 0; x <= y; x++)
	{
		Putpixel64k(x0 + x, y0 + y, color);
		Putpixel64k(x0 + x, y0 - y, color);
		Putpixel64k(x0 - x, y0 - y, color);
		Putpixel64k(x0 - x, y0 + y, color);
		Putpixel64k(x0 + y, y0 + x, color);
		Putpixel64k(x0 + y, y0 - x, color);
		Putpixel64k(x0 - y, y0 - x, color);
		Putpixel64k(x0 - y, y0 + x, color);
		
		if (d < 0)
		{
			d += x * 4 + 6;
		}
		
		else
		{
			d += (x - y) * 4 + 10;
			y--;
		}
	}
}






/**************************************************************************
      功能说明：画实心圆
      参数说明：x,y为圆心
     无返回值
**************************************************************************/
 void FillCircle(int x, int y, int r, int color)
{
	int tx = 0, ty = r, d = 3 - 2 * r, i;

	while( tx < ty)
	{
		// 画水平两点连线(<45度)
		for (i = x - ty; i <= x + ty; i++)
		{
			Putpixel64k(i, y - tx, color);
			if (tx != 0)	// 防止水平线重复绘制
				Putpixel64k(i, y + tx, color);
		}

		if (d < 0)			// 取上面的点
			d += 4 * tx + 6;
		else				// 取下面的点
		{
			// 画水平两点连线(>45度)
			for (i = x - tx; i <= x + tx; i++)
			{
				Putpixel64k(i, y - ty, color);
				Putpixel64k(i, y + ty, color);
			}

			d += 4 * (tx - ty) + 10, ty--;
		}

		tx++;
	}

	if (tx == ty)			// 画水平两点连线(=45度)
		for (i = x - ty; i <= x + ty; i++)
		{
			Putpixel64k(i, y - tx, color);
			Putpixel64k(i, y + tx, color);
		}
}

void delay0(int x)
 {
 	int i,j,k;
 	for(i=0;i<x;i++)
 	{
		for (j = 0; j < 1100; j++)
			for(k=0;k<100;k++);
		
	}
 } 