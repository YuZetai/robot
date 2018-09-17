#include<svgahead.h>
extern void forebodyhead(int x,int y);
extern void delay();
void moveaim(int x,int y)
{
	int i;
	unsigned int *cat;
	for(i=0;i<30;i++);
	{
		get_image(x-20,y-80,x+20,y-14,cat);
		forebodyhead(x,y);
		delay();
		put_image(x-20,y-80,x+20,y-14,cat);
		x+=2;
	}
}


/*逻辑大概是这样：pfang为上次移动的方向，pf/pb中的being为不同移动方式保存内存的指针（也就是说，左右移动就把pb变成1，上下移动则为pf），
而pf/pb中的front等存储某位置的像素情况（getimage），move代表移动方向的正负move代表移动方向的正负


*/



























//学长的移动程序，新输入的参数有：

int  movinglevel(int *pfang, int *aim, DOOR_WINDOW *d_w, BANYUN *banthing, THINGA * pdis, THING *thead, int * pju, int x0, int y0, int move, BACK *pb, FRONT *pf, SIET_HOUSE *psite)
{
	int zhuang;
	char key;                                                          /*按键*/
	int judge;
	int i = 0;                                                        /*循环变量*/
	if (*pju != 0)
	{
		return 1;
	}


	if (*pfang == 1)                                                  /*如果上一次是调用的上下移动函数*/
	{
		if ((pf->being) == 1)                                         /*判断指针指向的内存是否有图像*/
		{
			put_image(x0, y0, x0 + 45, y0 + 59, pf->front);           /*再将原来的背景图填补上去*/
		}
	}
	if (*pfang == 2)                                                  /*如果上次调用的是左右移动函数*/
	{
		if ((pb->being) == 1)                                        /*判断指针内的内存是否有图像*/
		{
			put_image(x0, y0, x0 + 35, y0 + 59, pb->back);           /*将原来的图像补上去*/
		}
	}
   
	if (move > 0)                                                    /*向右移动，move为正*/
	{
		zhuang=zhuangtai(1);
		for (i = 0; i< move + 1; i++)
		{
			get_image(x0 + i, y0, x0 + 35 + i, y0 + 59, pb->back);     /*先保存原先位置的背景图像*/
			paintside_right(x0 + 11 + i, y0);
			zhuang=zhuangtai(0);
			if (kbhit())
			{
					key = getch();
			}
            
			if (key == 0x1b)
			{
				*pfang = 2;
				*pju = 5;
				return 1;
			}
			judge = dis_raod(thead, x0 + i, y0, psite->house);
			if (judge != 0)
			{

				psite->currx = x0 + i;
				psite->curry = y0;
				*pfang = 2;
				judge = action(pfang, pju, aim, d_w, banthing ,pdis, thead, 4, psite, pb, pf);      /*一个判断,是否为可以影响到行走的障碍物 */
				if (judge == 1)
				{
					*pju = 4;
					put_image(psite->currx, psite->curry, psite->currx + 35, psite->curry + 59, pb->back);     /*再将原来的背景图填补上去*/
					return 1;
				}
			}
			delay0(1500);
			put_image(x0 + i, y0, x0 + 35 + i, y0 + 59, pb->back);     /*再将原来的背景图填补上去*/
			psite->currx = x0 + i;
			psite->curry = y0;

		}
		get_image(x0 + move, y0, x0 + 35 + move, y0 + 59, pb->back);
		paintside_right(x0 + 11 + move, y0);
	}

	if (move <= 0)                                                      /*向左移动，move为负*/
	{
		zhuang=zhuangtai(2);
		move = move*(-1);
		for (i = 0; i<move + 1; i++)
		{

			get_image(x0 - i, y0, x0 + 35 - i, y0 + 59, pb->back);        /*先保存原先位置的背景图像*/
			paintside_left(x0 + 11 - i, y0);	        /*复制上小机器人的图像*/
			zhuang=zhuangtai(0);
			if (kbhit())
			{
				key = getch();
			}		
			if (key == 0x1b)
			{
				*pfang = 2;
				*pju = 5;
				return 1;
			}
			judge = dis_raod(thead, x0 - i, y0, psite->house);
			if (judge != 0)
			{

				psite->currx = x0 - i;
				psite->curry = y0;
				put_image(x0 - i, y0, x0 + 35 - i, y0 + 59, pb->back);      /*再将原来的背景图填补上去*/
				*pfang = 2;
				judge = action(pfang, pju, aim,d_w, banthing , pdis, thead, 3, psite, pb, pf);      /*一个判断,是否为可以影响到行走的障碍物 */
				if (judge == 1)
				{

					*pju = 3;
					put_image(psite->currx, psite->curry, psite->currx, psite->curry + 59, pb->back);      /*再将原来的背景图填补上去*/
					return 1;
				}
			}
			delay0(1500);
			put_image(x0 - i, y0, x0 + 35 - i, y0 + 59, pb->back);      /*再将原来的背景图填补上去*/
			psite->currx = x0 - i;
			psite->curry = y0;

		}
		get_image(x0 - move, y0, x0 + 35 - move, y0 + 59, pb->back);
		paintside_left(x0 + 11 - move, y0);
	}

	pb->being = 1;
	*pfang = 2;

	return 0;
}



//int *pfang(代表方向的指针),int *pju,类BACK,FRONT 分别是正面身，侧面身时‘所用指向内存的结构’










//调用move 的函数，此处copy，过来参考原理
SIET_HOUSE *bizhangy(int *pfang,int *pju,int *aim, DOOR_WINDOW *d_w, BANYUN *banthing,SIET_HOUSE *robot,THING *pthing,THINGA *aimer,THING *thead,BACK *pb,FRONT*pf,int state)
{
    	int judge=0; 
    	int x_backz = robot->currx ;
    	int x_frontz1 = robot->currx + 35;
    	int x_frontz = robot->currx + 45;
    	int y_upz = robot->curry+40 ;
    	int y_downz = robot->curry +60;
	switch(state)
	{
		case 1:
			                put_image(robot->currx, robot->curry, robot->currx + 45, robot->curry + 59 , pf->front);     /*再将原来的背景图填补上去*/

	                        judge=movinglevel(pfang,aim,d_w, banthing ,aimer,thead,pju,robot->currx, robot->curry,pthing->x1-x_frontz-1, pb,pf,robot );
	                    //    getchar();
	                   //     put_image(robot->currx ,robot->curry, robot->currx+ 35 ,robot->curry  + 59, pb->back);     /*再将原来的背景图填补上去*/	
	//     getchar();
							if(judge==0)
							{
								movingver(pfang,aim,d_w, banthing ,aimer,thead,pju,robot->currx, robot->curry,y_upz-pthing->y2+15 , pb,pf,robot );
				//				getchar();
					//			put_image(robot->currx, robot->curry, robot->currx + 45, robot->curry + 59 , pf->front);     /*再将原来的背景图填补上去*/
					
							}	 
		//					getchar();
	                        pthing->yn=0;
	   
                            break;
		case 2:
			                put_image(robot->currx, robot->curry, robot->currx + 45, robot->curry + 59 , pf->front);     /*再将原来的背景图填补上去*/
	
                        	judge=movinglevel(pfang,aim,d_w, banthing ,aimer,thead,pju,robot->currx, robot->curry,pthing->x2-x_backz+1, pb,pf ,robot );	
             //           	put_image(robot->currx ,robot->curry, robot->currx+ 35 ,robot->curry  + 59, pb->back);     /*再将原来的背景图填补上去*/	
               
                        	if(judge==0)
                        	{
                        		movingver(pfang,aim,d_w, banthing ,aimer,thead,pju,robot->currx, robot->curry,y_downz-pthing->y1-1 , pb,pf,robot );
                //        		put_image(robot->currx, robot->curry, robot->currx + 45, robot->curry + 59 , pf->front);     /*再将原来的背景图填补上去*/
                        	}
	                        
	                        pthing->yn=0;
	               
        		            break;
        		            
        case 3:
        	                put_image(robot->currx ,robot->curry, robot->currx+ 35 ,robot->curry  + 59, pb->back);     /*再将原来的背景图填补上去*/	
        
                           	judge=movingver(pfang,aim,d_w, banthing ,aimer,thead,pju,robot->currx, robot->curry,y_upz-pthing->y2-1 , pb,pf,robot );	
                           	
              //             	put_image(robot->currx, robot->curry, robot->currx + 45, robot->curry + 59 , pf->front);     /*再将原来的背景图填补上去*/
                       
                           	if(judge==0)
                           	{
                           		movinglevel(pfang,aim,d_w, banthing ,aimer,thead,pju,robot->currx, robot->curry,pthing->x2-x_backz-1, pb,pf ,robot );	
              //             		put_image(robot->currx ,robot->curry, robot->currx+ 35 ,robot->curry  + 59, pb->back);     /*再将原来的背景图填补上去*/	
                           	}
    
                           	pthing->yn=0;
                           	
			                break;
       	case 4:
       		                put_image(robot->currx ,robot->curry, robot->currx+ 35 ,robot->curry  + 59, pb->back);     /*再将原来的背景图填补上去*/	
       		              
                     		judge=movingver(pfang,aim,d_w, banthing ,aimer,thead,pju,robot->currx, robot->curry, y_downz-pthing->y1+1, pb,pf,robot );	
          //           		put_image(robot->currx, robot->curry, robot->currx + 45, robot->curry + 59 , pf->front);     /*再将原来的背景图填补上去*/
             
                     		if(judge==0)//遇到其他障碍物则无视这个障碍物了 
                     		{
                     			movinglevel(pfang,aim,d_w, banthing ,aimer,thead,pju,robot->currx, robot->curry,pthing->x1-x_frontz1+1, pb,pf ,robot );	
             //        			put_image(robot->currx ,robot->curry, robot->currx+ 35 ,robot->curry  + 59, pb->back);     /*再将原来的背景图填补上去*/	
                     		}
        
                           	pthing->yn=0;
                        
			                break;
       		
	}
	return  robot;//返回机器人情况 
	                           		
}