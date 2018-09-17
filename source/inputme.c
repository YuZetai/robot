/*****************************************
本文件是关于简单输入法的一些函数
首次编写时间10月14日
编写人：黄昱恺

**********************************************/


#include"inputme.h"
#include"svgahead.h"

void interrupt(*oldint)(unsigned bp, unsigned di, unsigned si, unsigned ds, unsigned es, unsigned dx, unsigned cx, unsigned bx, unsigned ax, unsigned ip, unsigned cs, unsigned flags);




int * quanxcurr(void)
{
	static int xcurr;

	return &xcurr;
}


int * quanycurr(void)
{
	static int ycurr;

	return &ycurr;
}




/**************************************************
function:        guaninstal

description :    安装中断

Input :          p函数指针

out :           

*************************************************************/





/**************************************************
function:        newint

description :   制定位置显示光标

Input :         

out :           

*************************************************************/
void interrupt   newint(unsigned bp, unsigned di, unsigned si, unsigned ds, unsigned es, unsigned dx, unsigned cx, unsigned bx, unsigned ax, unsigned ip, unsigned cs, unsigned flags)
{
	static  gu_count = 0;

	static  gu_time = 1;

	int *px;                              
	int *py;
	
	px = quanxcurr();                                        /*指向输入的位置*/
	py = quanycurr();

	gu_count++;

	if (gu_count == 10)                                     /*中断中10次大约为1秒*/
	{
		gu_count = 0;
		gu_time = gu_time*(-1);

	}

		if (gu_time == 1)
		{
			linever((*px)-1, *py, (*px)-1, *py + 20, 2, 0);         /*画出光标*/
		}
		else
		{
			linever((*px)-1, *py, (*px)-1, *py + 20, 2, 0x9490);
		}

	outportb(0x20, 0x20);
}

/**************************************************
function:       put_English

description :    在指定的地方输出英文

Input :          x1,y1 输出位置坐标，ascii为该英文的ASCII码

out :           在指定位置输出英文字母

*************************************************************/
void  putEnglish(int x1, int y1,int ascii,int mx,int my,int color )
{
	char * English_save;                                /*定义指向字模存取的指针*/

	int x0;                                           /*定义记录位置的变量个*/
	int y0;
	int yt;
	int xt;

	int i = 0;                                            /*循环变量*/
	int j = 0;
	int k = 0;
	unsigned char mask[] = { 0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01 };
	unsigned long offest;                            /*计算英文字母在汉字库中的偏移量*/
	FILE * fh;                                     /*定义一个文件指针*/
	const char *fname = "HZK\\ASC16.DZK";
	fh = fopen(fname, "rb");
   if (fh == NULL)
	{
		printf("the hzk can't open\n");
		delay(1000);
		exit(1);
	}



   English_save = (char *)malloc( 32* sizeof(char));




	offest = ascii * 32l;
	fseek(fh, offest, 0);
	fread(English_save, 32, 1, fh);

	x0 = x1;                                         /*记录输入位置*/
	y0 = y1;
	fclose(fh);
	while (i <16)                                    /*循环判断输出英文字母*/
	{
		for (yt = 0; yt < my; yt++)
		{
			for (j = 0; j < 2; j++)
			{
				for (k = 0; k < 8; k++)
				{
					for (xt = 0; xt < mx; xt++)
					{
						if ((English_save[2 * i + j] & mask[k % 8]) != 0)
						{
							Putpixel64k(x0 , y0 , color);

						}
						x0++;
					}
				}

			}
			x0 = x1;
			y0++;
		}
		i++;
	}


	free(English_save);
}


/**************************************************
function:       putchinese

description :    在指定的地方输出中文

Input :          x1,y1 输出位置坐标，为该中文的偏移量

out :           在指定位置输出文字

*************************************************************/
void  putchinese(int x1, int y1, int neima, int color)
{

	FILE * fhzk_p;               /*定义文件指针*/

	char *mat;                                        /*存储字模的指针*/

	int x, y;                                         /*位置存储*/

	int i, j,k;                                         /*简单的循环变量*/
	char a[5];
	char qhs[3];
	char whs[3];
	unsigned char mask[] = { 0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01 };
	unsigned char qh, wh;
	unsigned long offset;

	fhzk_p = fopen("HZK\\hzk16", "rb");                         /*打开汉字库*/

	if (fhzk_p == NULL)
	{
		printf("the hzk can't open\n");
		delay(1000);
		exit(1);
	}


	mat = (char *)malloc(32 * sizeof(char));                           /*分配内存空间*/
	if (mat == NULL)
	{
		printf("there is no place\n");
		exit(1);
	}
	itoa(neima, a, 10);                                                /*将区码和位码分开*/
	for (i = 0; i < 2; i++)
	{
		qhs[i] = a[i];
	}
	qhs[2] = '\0';

	for (i = 2; i < 4; i++)
	{
		whs[i - 2] = a[i];
	}
	whs[2] = '\0';
	qh = atoi(qhs);
	wh = atoi(whs);

	offset = (94 * (qh - 1) + (wh - 1)) * 32L;                       /*计算偏移量*/
	fseek(fhzk_p, offset, SEEK_SET);
	fread(mat, 32, 1, fhzk_p);
	fclose(fhzk_p);
	x = x1;
	y = y1;
	i=0;
	while (i < 16)
	{

		for (j = 0; j < 2; j++)
		{
			for (k = 0; k < 8; k++)
			{
				if ((mask[k % 8] & mat[2 * i + j]) != 0)
				{
					Putpixel64k(x, y, color);
				}
				x++;
			}

		}
		x=x1;
		y++;
		i++;
	}

	free(mat);

}


/**************************************************
function:       inputmethod

description :    在指定的地方进行输入法

Input :          x1,y1 输出位置坐标，color为汉字的颜色

out :           在指定位置输出文字

*************************************************************/

int  inputmethed(int x1, int y1,char * hanzi, int color)
{
	int count_num=0;
	int inix0;
	int *pxcur;
	int *pycur;
	int count = 0;                                              /*计数单位*/
	int judge = 0;
	int pos = 0;                                         /*记录拼音在拼音库中的位置*/
	int page = 1;
	int i = 0;                                                  /*简单循环变量*/
	int xcurr = x1;
	int ycurr = y1;
	int x_ying=x1;                                        /*记录实时位置*/
	int y_ying=y1;
	int key;                                             /*记录键值*/
	Pinying  *thespe ;
	int asc;                         					   /*记录ASCII码*/
	int n = 0;                                           /*记录拼音个数*/
	char spellable[10] = { '\0'};                       /*存储拼音*/
	thespe=(Pinying *)malloc(411*sizeof(Pinying));                                      /*定义拼音结构*/
	if (thespe == NULL)
	{
		printf("there is no plasc\n");
		exit(1);
	}

	memset(hanzi,'\0',40);
	pxcur = quanxcurr();
	*pxcur = xcurr;
	pycur = quanycurr();
	*pycur = ycurr;
	oldint = getvect(0x1c);                               /*加载中断*/

    inix0=x1;

	disable();
	setvect(0x1c, newint);
	enable();
	get_list(thespe);

	while (1)
	{
		key = bioskey(0);
		asc= key & 0x00ff;                                                    /*获得ASCII码*/

		if ((('a' <= asc) && (asc <= 'z')) || (('1' <= asc) && (asc <= '9')) || (key == Backspace) || (key == BLANK) || (key == PLUS) || (key == MOUES)||(key==ENTER)||(key==ESC))   /*确定是这些键值*/
		{
			if ((asc>= 'a') && (asc<= 'z'))
			{
				page = 1;
				if (judge == 0)                                              /*进行画框*/
				{
					put_case(xcurr, ycurr,&judge);
					judge = 1;
				}
				putEnglish(x_ying, y_ying+30, asc, 1, 1, 0xcece);                /*显示输入的拼音*/

				spellable[n++] =asc;                                        /*存储输入的拼音*/

				if (n >= 10)                                                  /*如果输入的音节过多的话*/
				{


						key = 0;
						asc =0;
						n++;                                                  /*否则不做处理，接着重新循环*/
						continue;

				}

				if (search(thespe, spellable, &pos) == 0)
				{
					x_ying = x_ying +9;
					continue;
				}

				draw_pagechinese(xcurr, ycurr, thespe, pos, page,color);

			 }

			if (('1' <= asc) && (asc <= '5') || (key == BLANK))          /*如果输入的是数字键或者是空格键*/
			{
				if (spellable[0] == '\0')
				{
					continue;
				}
				if(count_num>20)
				{
					continue;
				}
				if ((key == BLANK))
				{
					asc = '1';
					if (count < 20)
					{
						savehanzi(pos, asc, page, hanzi, &count, thespe);
					}
					else                                                 /*如果存储的汉字满了*/
					{
						count = 0;
						memset(hanzi, '\0', 40);
					}
					puthz(xcurr, ycurr, pos, asc, page,thespe, color);  /*在指定的地方输出汉字*/
				}
				else
				{
					if (count < 20)
					{
						savehanzi(pos, asc, page, hanzi, &count, thespe);
					}
					else                                                 /*如果存储的汉字满了*/
					{
						count = 0;
						memset(hanzi, '\0', 40);
					}
					puthz(xcurr, ycurr, pos, asc, page, thespe, color);  /*在指定的地方输出汉字*/
				}

                    count_num++;
					distoryboard(xcurr, ycurr,&judge);               /*消除框架 */

					memset(spellable, '\0', 10);                          /*清空字母表*/


					xcurr = xcurr + 20;                                    /*移动输入位置，为下一次输入做准备*/
					*pxcur = xcurr;

					linever(xcurr - 21, ycurr, xcurr - 21, ycurr + 20, 2, 0x9490);   /*消除光标*/
					judge = 0;
					x_ying = xcurr;
					n = 0;
					pos = 0;
					page = 1;

					continue;
			}

			if ((key == PLUS) || (key == MOUES))                      /*如果按下翻页键*/
			{
				if (spellable[0] == '\0')
				{
					continue;
				}
				if (key == PLUS)                                      /*如果向下翻页*/
				{
					page++;
					//put_case(x1, y1, &judge, saveboard);       /*先清空画框*/
					draw_pagechinese(xcurr, ycurr, thespe, pos, page, color);
				}

				else                                                 /*否则就是按下翻页上键*/
				{
					if (page == 1)
					{
						continue;
					}
					page--;
					draw_pagechinese(xcurr, ycurr, thespe, pos, page, color);
				}
				continue;
			}


			if (key == Backspace)
			{

				if(x_ying<=inix0)
				{
					continue;
				}
				if (spellable[0] != 0)                            /*有音消字*/
				{
					if (n >= 10)
					{
						n--;
					}
					else
					{
						spellable[n - 1] = '\0';
						n--;
						if (spellable[0]=='\0')                        /*如果这是最后一个音节*/
						{
							distoryboard(xcurr, ycurr, &judge);        /*消除框架 */
							n = 0;
							x_ying = xcurr;
						}

						else                                                     /*如果不是最后一个音节*/
						{
							bar(xcurr, ycurr + 30,xcurr+409,ycurr+58,0xffff);
							for (i = 0; spellable[i] != '\0'; i++)
							{
								putEnglish(xcurr + 9 * i, ycurr + 30, spellable[i], 1, 1, color);

							}

							if (search(thespe, spellable, &pos) == 0)
							{
								x_ying = xcurr + 9 * i;
								continue;
							}

							//	put_case(x1, y1, &judge, saveboard);           /*先清空画框*/
							x_ying = xcurr + 9 * i;
							draw_pagechinese(xcurr, ycurr, thespe, pos, page, color);
						}
					}
					count_num--;
					continue;
				}

				else                                                     /*无音消字*/
				{
					xcurr = xcurr - 20;
					*pxcur = xcurr;
					linever(xcurr + 19, ycurr, xcurr +19, ycurr + 20, 2, 0x9490);   /*消除光标*/
					bar(xcurr, ycurr, xcurr + 20, ycurr + 20, 0x9490);
					count = count - 2;
					hanzi[count] = '\0';
					hanzi[count + 1] = '\0';
					x_ying = xcurr;
					count_num--;
					continue;
				}
			}


			if ((key == ESC)||(key==ENTER))                                          /*退出输入法*/
			{
			if (spellable[0] != '\0')
				{
					distoryboard(xcurr - 20, ycurr, &judge);               /*消除框架 */
					free(thespe);
				}
             	free(thespe);
			   //	free(saveboard);
				break;
			}

			

	  }
	  x_ying = x_ying + 9;                                         /*y拼音位置后移*/
   }
   

   
   setvect(0x1c, oldint);
   
   linever(xcurr, ycurr, xcurr, ycurr + 20, 2, 0xffff);   /*消除光标*/

   return 1;
  }



/**************************************************
function:       get_list

description :   得到拼音库中的内容

Input :         spell_list为相应的结构指针

out：          无

*************************************************************/

void  get_list(Pinying *spell_list)
{
	FILE  *fp;
	int i = 0;

	int str = 0;                                      /*定义中间变量*/
	char spell[10] = "\0";

	fp = fopen("pinyin.txt", "r");         /*打开文件*/
	if (fp == NULL)
	{
		printf("the file can open\n");
		delay(1000);
		exit(1);
	}

	while (feof(fp) == 0)
	{
		fscanf(fp, "%s%d", spell, &str);                /*读取内容*/
		spell_list[i].neima = str;
		strcpy(spell_list[i].spell, spell);
		i++;
	}


	fclose(fp);                                        /*关闭文件*/
}




/**************************************************
function:       put_case

description :   画出输入的框子

Input :         x_now ,y_now 为画框的位置，savebo是指向存储之前的区域

out：          无

*************************************************************/
void  put_case(int x_now, int y_now,int *judge0)
{

	save_image(x_now,y_now+30,x_now+410,y_now+94) ;
	bar(x_now, y_now + 30, x_now + 409, y_now + 58, 0xffff);
	bar(x_now, y_now + 58, x_now + 409, y_now + 90, 0xFF9D76);

	*judge0 = 1;
}

/**************************************************
function:       search

description :   搜寻输入的拼音在拼音库里对应的位置

Input :         spell_list为结构指针
				spellable为存储拼音的结构
				position为配对的位置

out：          无

*************************************************************/

int  search(Pinying *spell_list, char *spellable, int * position)
{
	int i = 0;                                        /*循环变量*/
	while (i < 410)
	{
		if (strcmp(spell_list[i].spell, spellable) == 0)
		{
			*position = i;
			return 1;
		}
		i++;
	}
	return 0;
}



/**************************************************
function:       draw_pagechinese

description :   在框内显示出匹配的汉字选项

Input :


out：          无

*************************************************************/
void draw_pagechinese(int x0, int y0, Pinying *spell_list, int hzpos, int page, int color)
{
	int i;
	int qwma1 = spell_list[hzpos].neima;                                        /*这个拼音第一个字的区位码*/
	int qwma2 = spell_list[hzpos + 1].neima;                                  /*下一个拼音第一个字的区位码*/
	int n;
	bar(x0, y0 + 58,x0+409,y0+90, 0xFF9D76);
	

	n = qwma2 - qwma1;                                                        /*中间有多少汉字*/
	if ((page * 5) > n)                                                            /*如果汉字不够显示一页了*/
	{
		n = qwma2 - qwma1 - (page - 1) * 5;
	}
	else
	{
		n = 5;
	}
	for (i = 0; i < n; i++)
	{
		putEnglish(x0+i*35, y0 + 63, 49 + i, 1, 1, color);             /*显示字号*/

		putchinese(x0 + 20+i*34, y0 + 63, qwma1+(page-1)*5+i, color);

	}
}


/**************************************************
function:       puthz

description :   在输入的地方显示所选的汉字

Input :          x1,y1为输出的位置 position为拼音对应位置，
				 ascii为输入的数字ASCII码
				 page 为当前页数
				 spell_list为对应结构指针
				 color为颜色

out：


*************************************************************/

void puthz(int x1, int y1, int  position, int ascii, int page, Pinying *spell_list, int  color)
{

	int t = 0;                                              /*表示所选的字号*/
	int qw = 0;
	t = ascii - '0';
	qw = spell_list[position].neima;

	putchinese(x1, y1, qw + (page - 1) * 5 + t-1, color);

}

/**************************************************
function:       put_word

description :   在输入的地方显示输入的英文

Input :          x1,y1为输出的位置 position为拼音对应位置，
				ascii为输入的数字ASCII码
page 为当前页数
spell_list为对应结构指针
color为颜色

out：


*************************************************************/
void put_word(int x0, int y0, char * spell, int color)
{
	int i;
	for (i = 0; *spell != '\0'; i++)
	{
		putEnglish(x0 + i * 16, y0, *(spell + i), 1, 1, color);
	}

}

/**************************************************
function:       distoryboard

description :   消除输入法的选字框

Input :         x0,y0为输入汉字的位置，judebo指向判断是否画框的变量，
				savebo是指向存储之前的区域


out：          无

*************************************************************/

void distoryboard(int x0, int y0,int *judebo)
{
	printf_image(x0, y0 + 30, x0 + 410, y0 + 94);
	*judebo = 0;

}

/**************************************************
function:       savehanzi

description :   存储输入法输出的汉字

Input :


out：          无

*************************************************************/

void savehanzi(int  position, int ascii, int page, char * hanzi,int * count, Pinying *spell_list )
{
	int i;
	int t = 0;
	int qw = 0;
	int neima;
	char a[5];
	char qhs[3];
	char whs[3];
	unsigned char qh, wh;
	t = ascii - '0';
	qw = spell_list[position].neima;
	neima = qw + (page - 1) * 5 + t - 1;
	itoa(neima, a, 10);                                                /*将区码和位码分开*/
	for (i = 0; i < 2; i++)
	{
		qhs[i] = a[i];
	}
	qhs[2] = '\0';

	for (i = 2; i < 4; i++)
	{
		whs[i - 2] = a[i];
	}
	whs[2] = '\0';
	qh = atoi(qhs);
	wh = atoi(whs);
	hanzi[*count] = qh + 0xa0;
	hanzi[(*count) + 1] = wh + 0xa0;
	*count  = *count  + 2;
}

/**************************************************
function:       inputEnglish

description :   消除输入法的选字框

Input :         x0,y0为输入英文和数字的位置，judebo指向判断是否画框的变量，
                    


out：          无

*************************************************************/

void  inputEnglish(int x1, int y1, char * mima,int color)
{

	int xcurr=x1;
	int ycurr=y1;
	int *px;
	int *py;
	int key;                                             /*记录键值*/
	int asc;                                             /*记录ASCII码*/
	int count = 0;
	memset(mima,'\0',16);                   /*存储被框遮挡的图像*/
	px = quanxcurr();
	py = quanycurr();

	*px = xcurr;
	*py = ycurr;

	oldint = getvect(0x1c);                               /*加载中断*/
	disable();
	setvect(0x1c, newint);
	enable();
	while (1)
	{
		key = bioskey(0);
		asc = key & 0x00ff;                                                    /*获得ASCII码*/
		if (key == Backspace)
		{
			//ar(xcurr, ycurr, xcurr + 15, ycurr + 16, 0xffff);
			count = count - 1;
			mima[count] = '\0';
			xcurr = xcurr - 16;
			*px = xcurr;
			bar(xcurr, ycurr, xcurr + 16, ycurr + 16, 0x9490);
			linever(xcurr + 16, ycurr, xcurr + 16, ycurr + 20, 2,0x9490);
			continue;
		}
		if ((key == ESC) || (key == ENTER))
		{

			break;
		}
		
		putEnglish(xcurr, ycurr, asc, 1, 1, color);
		xcurr = xcurr + 16;
		*px = xcurr;
		linever(xcurr - 17, ycurr, xcurr - 17, ycurr + 20, 2, 0x9490);

		
		mima[count] = asc;
		count++;
	}
	setvect(0x1c, oldint);
}




/**************************************************
function:       check_out

description :   核对所输入的信息是不是和文件中的一致

Input :         



out：          如果信息一致返回1，否则返回0

*************************************************************/

int checkover(char * mima, const char * fname)
{
	FILE *fp;                     /*定义文件指针*/
	char * checko;
	fp = fopen(fname, "rt");
	if (fp == NULL)
	{
		printf("the file can not open\n");
		exit(1);
	}

	checko = (char *)malloc(15 * sizeof(char));

	if (checko == NULL)
	{
		printf("the is no place");
		exit(1);
	}

	fscanf(fp, "%s", checko);
	if (strcmp(checko, mima) == 0)
	{
		fclose(fp);
		return 1;
	}
	else
	{
		fclose(fp);
		return 0;
	}

}




/**************************************************
function:        check_in

description :   将所要填写的信息填写到文件中

Input :          



out：          如果信息一致返回1，否则返回0

*************************************************************/

void  check_in(char * mima, const char * fname)
{
	FILE *fp;                                        /*定义文件指针*/

	fp = fopen(fname, "wt");
	if (fp == NULL)
	{
		printf("the file can not open\n");
		exit(1);
	}

	fprintf(fp, "%s", mima);
	fclose(fp);
}
