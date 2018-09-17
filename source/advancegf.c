#include<basicgf.h>
#include<svgahead.h>
#include<math.h>

void bow(int,int,int,int);
void semicircle_up(int,int,int,int);
void semicircle_down(int,int,int,int);
void fill_bow_right_up(int,int,int,int);
void fill_bow_left_up(int,int,int,int);
void fill_bow_right_down(int,int,int,int);
void fill_bow_left_down(int,int,int,int);
void fill_bow_down(int,int,int,int);
void fill_bow_left(int,int,int,int);
void fill_bow_right(int,int,int,int);
void bar_round(int,int,int,int,int,int,int);
void bow_right_up(int,int,int,int);
void bow_right_down(int,int,int,int);
void bow_left_up(int,int,int,int);
void bow_left_down(int,int,int,int);

/*只能画竖直方向的实心椭圆
输入：两个圆心坐标及半径，颜色*/
void Fillellipse(int x1,int y1,int x2,int y2,int r,int color)
{
	FillCircle(x1,y1,r,color);
	FillCircle(x2,y2,r,color);
	bar(x1-r,y1,x2+r,y2,color);
}


/*非实心椭圆*/
void ellipse(int x1,int y1,int x2,int y2,int r,int color)
{
	semicircle_up(x2,y2,r,color);
	semicircle_down(x1,y1,r,color);
	linever(x1-r,y1,x1-r,y2,1,color);
	linever(x2+r,y1,x2+r,y2,1,color);
}

/*半圆（非实心）*/
void semicircle_up(int x0,int y0,int r,int color)
{
	int x, y, d;
	y = r;
	d = 3 - r << 1;

	for (x = 0; x <= y; x++)
	{
		Putpixel64k(x0 + x, y0 + y, color);
		Putpixel64k(x0 - x, y0 + y, color);
		Putpixel64k(x0 + y, y0 + x, color);
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

void semicircle_down(int x0,int y0,int r,int color)
{
	int x, y, d;
	y = r;
	d = 3 - r << 1;
	
	for (x = 0; x <= y; x++)
	{
		Putpixel64k(x0 + x, y0 - y, color);
		Putpixel64k(x0 - x, y0 - y, color);
		Putpixel64k(x0 + y, y0 - x, color);
		Putpixel64k(x0 - y, y0 - x, color);
		
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


/*弧*/
void bow(int x0,int y0,int r,int color)//弧度固定
{
	int x,y,d;
	y = r;
	d = 3-r<<1;
	
	for(x=0;x<=y/4;x++)
	{
		Putpixel64k(x0 + x, y0 + y, color);
		Putpixel64k(x0 - x, y0 + y, color);
	    if(d<0)
		{
			d+=x*4+6;
		}
		else{
			d+=(x-y)*4+10;
			y--;
		}
	}
}

void bow_right_up(int x,int y,int r,int color)
{
	int tx=0,d;
	while(tx<=r)
	{
		d = sqrt(r*r-tx*tx);
		Putpixel64k(x+d,y-tx,color);
		tx++;
	}
}

void bow_right_down(int x,int y,int r,int color)
{
	int tx=0,d;
	while(tx<=r)
	{
		d = sqrt(r*r-tx*tx);
		Putpixel64k(x+d,y+tx,color);
		tx++;
	}
}

void bow_left_up(int x,int y,int r,int color)
{
	int tx=0,d;
	while(tx<=r)
	{
		d = sqrt(r*r-tx*tx);
		Putpixel64k(x-d,y-tx,color);
		tx++;
	}
}

void bow_left_down(int x,int y,int r,int color)
{
	int tx=0,d;
	while(tx<=r)
	{
		d = sqrt(r*r-tx*tx);
		Putpixel64k(x-d,y+tx,color);
		tx++;
	}
}

/*填充四分之一圆，右上*/
void fill_bow_right_up(int x,int y,int r,int color)
{
	int tx = 0, ty = r, d = 3 - 2 * r, i;
	while( tx < ty)
	{
		// 画水平两点连线(<45度)
		for (i = x; i <= x + ty; i++)
		{
			Putpixel64k(i, y - tx, color);
		}

		if (d < 0)			// 取上面的点
			d += 4 * tx + 6;
		else				// 取下面的点
		{
			// 画水平两点连线(>45度)
			for (i = x; i <= x + tx; i++)
			{
				Putpixel64k(i, y - ty, color);
				
			}

			d += 4 * (tx - ty) + 10, ty--;
		}

		tx++;
	}
	if (tx == ty)			// 画水平两点连线(=45度)
		for (i = x; i <= x + ty; i++)
		{
			Putpixel64k(i, y - tx, color);
			
		}
}

void fill_bow_left_up(int x,int y,int r,int color)
{
	int tx=0,ty=r,i;
	double sx;
	while(tx<=ty)
	{
		sx = sqrt(r*r-tx*tx);
		for(i=x-sx;i<=x;i++)
		{
			Putpixel64k(i,y-tx,color);
		}
		tx++;
	}
}

void fill_bow_right_down(int x,int y,int r,int color)
{
	int tx=0,ty=r,i;
	double sx;
	while(tx<=ty)
	{
		sx = sqrt(r*r-tx*tx);
		for(i=x;i<=x+sx;i++)
		{
			Putpixel64k(i,y+tx,color);
		}
		tx++;
	}
}

void fill_bow_left_down(int x,int y,int r,int color)
{
	int tx=0,ty=r,i;
	double sx;
	while(tx<=ty)
	{
		sx = sqrt(r*r-tx*tx);
		for(i=x-sx;i<=x;i++)
		{
			Putpixel64k(i,y+tx,color);
		}
		tx++;
	}
}

void fill_bow_down(int x,int y,int r,int color)
{
	int tx = 0, ty = r,i;
	float d = r/1.414;
	double sx;
	while(tx<=ty)
	{
		if(tx<d)
		{
			for(i=x-tx;i<=x+tx;i++)
		    {
			    Putpixel64k(i,y+tx,color);
				
		    }
		}
        else
		{
			for(i=x-sx;i<=x+sx;i++)
			{
				Putpixel64k(i,y+tx,color);	
			}
		}
		tx++;
		sx = sqrt(r*r-tx*tx);
	}
}

void fill_bow_left(int x,int y,int r,int color)
{
	int ty = 0, tx = r,i;
	float d = r/1.414;
	double sy;
	while(ty<=tx)
	{
		if(ty<d)
		{
			for(i=y-ty;i<=y+ty;i++)
		    {
			    Putpixel64k(x-ty,i,color);
				
		    }
		}
        else
		{
			for(i=y-sy;i<=y+sy;i++)
			{
				Putpixel64k(x-ty,i,color);	
			}
		}
		ty++;
		sy = sqrt(r*r-ty*ty);
	}
}

void fill_bow_right(int x,int y,int r,int color)
{
	int ty = 0, tx = r,i;
	float d = r/1.414;
	double sy;
	while(ty<=tx)
	{
		if(ty<d)
		{
			for(i=y-ty;i<=y+ty;i++)
		    {
			    Putpixel64k(x+ty,i,color);
				
		    }
		}
        else
		{
			for(i=y-sy;i<=y+sy;i++)
			{
				Putpixel64k(x+ty,i,color);	
			}
		}
		ty++;
		sy = sqrt(r*r-ty*ty);
	}
}

/*圆角矩形*/
void bar_round(int x,int y,int length,int height,int r,int thick,int color)
{
	bar(x-length/2+r,y-height/2,x+length/2-r,y+height/2,color);
	bar(x-length/2,y-height/2+r,x+length/2,y+height/2-r,color);
	fill_bow_left_up(x-length/2+r,y-height/2+r,r,color);
	fill_bow_left_down(x-length/2+r,y+height/2-r,r,color);
	fill_bow_right_up(x+length/2-r,y-height/2+r,r,color);
	fill_bow_right_down(x+length/2-r,y+height/2-r,r,color);
	linelevel(x-length/2+r,y-height/2,x+length/2-r,y-height/2,thick,0);
	linelevel(x-length/2+r,y+height/2,x+length/2-r,y+height/2,thick,0);
	linever(x-length/2,y-height/2+r,x-length/2,y+height/2-r,thick,0);
	linever(x+length/2,y-height/2+r,x+length/2,y+height/2-r,thick,0);
    bow_right_up(x+length/2-r,y-height/2+r,r,0);
	bow_left_up(x-length/2+r,y-height/2+r,r,0);
	bow_left_down(x-length/2+r,y+height/2-r,r,0);
	bow_right_down(x+length/2-r,y+height/2-r,r,0);
}

void bar_round_with_shadow(int x,int y,int length,int height,int r,int thick,int color)
{
	bar(x-length/2+r,y-height/2,x+length/2-r,y+height/2,color);
	bar(x-length/2,y-height/2+r,x+length/2,y+height/2-r,color);
	fill_bow_left_up(x-length/2+r,y-height/2+r,r,color);
	fill_bow_left_down(x-length/2+r,y+height/2-r,r,color);
	fill_bow_right_up(x+length/2-r,y-height/2+r,r,color);
	fill_bow_right_down(x+length/2-r,y+height/2-r,r,color);
	linelevel(x-length/2+r,y-height/2,x+length/2-r,y-height/2,thick,65535);
	linelevel(x-length/2+r,y+height/2,x+length/2-r,y+height/2,thick*3,0);
	linever(x-length/2,y-height/2+r,x-length/2,y+height/2-r,thick,65535);
	linever(x+length/2,y-height/2+r,x+length/2,y+height/2-r,thick*2,0);
    bow_right_up(x+length/2-r,y-height/2+r,r,0);
	bow_left_up(x-length/2+r,y-height/2+r,r,65535);
	bow_left_down(x-length/2+r,y+height/2-r,r,65535);
	bow_right_down(x+length/2-r,y+height/2-r,r,0);
}