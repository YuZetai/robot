#include"main.h"


void movedown(ROBOT_CASE *robot_position)
{
	int i,x0,y0,count=0;//count用于计步，改变双脚移动情况
	(*robot_position).leg_left=0;
	(*robot_position).leg_right=0;
	(*robot_position).leg=1;
	(*robot_position).cat = (unsigned int*)malloc(44*71*sizeof(unsigned int));
	get_image((*robot_position).x-21,(*robot_position).y-80,(*robot_position).x+23,(*robot_position).y-9,(*robot_position).cat);
	for(i=0;i<200;i++)
	{
		if(count>=5)
		{
			(*robot_position).leg = !(*robot_position).leg;
			count=0;
		}
		forebodyhead(*robot_position);
		delay0(150);
		put_image((*robot_position).x-21,(*robot_position).y-80,(*robot_position).x+23,(*robot_position).y-9,(*robot_position).cat);
		y0 = (*robot_position).y+3;
		
		get_image((*robot_position).x-21,y0-80,(*robot_position).x+23,y0-9,(*robot_position).cat);
        if((*robot_position).leg)
		{
			(*robot_position).leg_right=0;
			(*robot_position).leg_left--;
		}
		else
		{
			(*robot_position).leg_left=0;
			(*robot_position).leg_right--;
		}
		(*robot_position).y = y0;
        count++;
		
		
	}
	free((*robot_position).cat);
}


void moveup(ROBOT_CASE *robot_position)//范围：范围：x+-20,y-80~y-14;
{
	int i,x0,y0,count=0;//count用于计步，改变双脚移动情况
	(*robot_position).leg_left=0;
	(*robot_position).leg_right=0;
	(*robot_position).leg=1;
	(*robot_position).cat = (unsigned int*)malloc(42*68*sizeof(unsigned int));
	get_image((*robot_position).x-20,(*robot_position).y-80,(*robot_position).x+22,(*robot_position).y-12,(*robot_position).cat);
	for(i=0;i<200;i++)
	{
		if(count>=5)
		{
			(*robot_position).leg = !(*robot_position).leg;
			count=0;
		}
		backbodyhead(*robot_position);
		delay0(150);
		put_image((*robot_position).x-20,(*robot_position).y-80,(*robot_position).x+22,(*robot_position).y-12,(*robot_position).cat);
		y0 = (*robot_position).y-3;
		
		get_image((*robot_position).x-20,y0-80,(*robot_position).x+22,y0-12,(*robot_position).cat);
        if((*robot_position).leg)
		{
			(*robot_position).leg_right=0;
			(*robot_position).leg_left--;
		}
		else
		{
			(*robot_position).leg_left=0;
			(*robot_position).leg_right--;
		}
		(*robot_position).y = y0;
        count++;
		
		
	}
	free((*robot_position).cat);
}

void moveright(ROBOT_CASE *robot_position)//范围：x-20~x+35,y-80~y-5
{
	int i,x0,y0,count=0,hand_count=0;//count用于计步，改变双脚移动情况,hand_count手部动作
	(*robot_position).leg_left=0;
	(*robot_position).leg_right=0;
	(*robot_position).leg=1;
	(*robot_position).cat = (unsigned int*)malloc(55*75*sizeof(unsigned int));
	(*robot_position).hand_right=0;
	(*robot_position).hand=0;
	get_image((*robot_position).x-20,(*robot_position).y-80,(*robot_position).x+35,(*robot_position).y-5,(*robot_position).cat);
	for(i=0;i<200;i++)
	{
		if(count>=5)
		{
			(*robot_position).leg = !(*robot_position).leg;
			count=0;
		}
		if(hand_count>=10)
		{
			(*robot_position).hand=!(*robot_position).hand;
			hand_count=0;
		}
		right(*robot_position);
		delay0(150);
		put_image((*robot_position).x-20,(*robot_position).y-80,(*robot_position).x+35,(*robot_position).y-5,(*robot_position).cat);
		x0 = (*robot_position).x+3;
		
		get_image(x0-20,(*robot_position).y-80,x0+35,(*robot_position).y-5,(*robot_position).cat);
        if((*robot_position).leg)
		{
			(*robot_position).leg_right=0;
			(*robot_position).leg_left--;
		}
		else
		{
			(*robot_position).leg_left=0;
			(*robot_position).leg_right--;
		}
		if((*robot_position).hand)
		{
			(*robot_position).hand_right++;
		}
		else
		{
			(*robot_position).hand_right--;
		}
		(*robot_position).x = x0;
        count++;
		hand_count++;
		
	}
	free((*robot_position).cat);
}

void moveleft(ROBOT_CASE *robot_position)//范围：x-23~x+20,y-80~y-9
{
	int i,x0,y0,count=0;//count用于计步，改变双脚移动情况
	(*robot_position).leg_left=0;
	(*robot_position).leg_right=0;
	(*robot_position).leg=1;
	(*robot_position).cat = (unsigned int*)malloc(45*72*sizeof(unsigned int));
	get_image((*robot_position).x-23,(*robot_position).y-80,(*robot_position).x+22,(*robot_position).y-8,(*robot_position).cat);
	for(i=0;i<200;i++)
	{
		if(count>=5)
		{
			(*robot_position).leg = !(*robot_position).leg;
			count=0;
		}
		left(*robot_position);
		delay0(150);
		put_image((*robot_position).x-23,(*robot_position).y-80,(*robot_position).x+22,(*robot_position).y-8,(*robot_position).cat);
		x0 = (*robot_position).x-3;
		
		get_image(x0-23,(*robot_position).y-80,x0+22,(*robot_position).y-8,(*robot_position).cat);
        if((*robot_position).leg)
		{
			(*robot_position).leg_right=0;
			(*robot_position).leg_left--;
		}
		else
		{
			(*robot_position).leg_left=0;
			(*robot_position).leg_right--;
		}
		(*robot_position).x = x0;
        count++;
		
		
	}
	free((*robot_position).cat);
}
