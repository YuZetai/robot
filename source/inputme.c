/*****************************************
���ļ��ǹ��ڼ����뷨��һЩ����
�״α�дʱ��10��14��
��д�ˣ�������

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

description :    ��װ�ж�

Input :          p����ָ��

out :           

*************************************************************/





/**************************************************
function:        newint

description :   �ƶ�λ����ʾ���

Input :         

out :           

*************************************************************/
void interrupt   newint(unsigned bp, unsigned di, unsigned si, unsigned ds, unsigned es, unsigned dx, unsigned cx, unsigned bx, unsigned ax, unsigned ip, unsigned cs, unsigned flags)
{
	static  gu_count = 0;

	static  gu_time = 1;

	int *px;                              
	int *py;
	
	px = quanxcurr();                                        /*ָ�������λ��*/
	py = quanycurr();

	gu_count++;

	if (gu_count == 10)                                     /*�ж���10�δ�ԼΪ1��*/
	{
		gu_count = 0;
		gu_time = gu_time*(-1);

	}

		if (gu_time == 1)
		{
			linever((*px)-1, *py, (*px)-1, *py + 20, 2, 0);         /*�������*/
		}
		else
		{
			linever((*px)-1, *py, (*px)-1, *py + 20, 2, 0x9490);
		}

	outportb(0x20, 0x20);
}

/**************************************************
function:       put_English

description :    ��ָ���ĵط����Ӣ��

Input :          x1,y1 ���λ�����꣬asciiΪ��Ӣ�ĵ�ASCII��

out :           ��ָ��λ�����Ӣ����ĸ

*************************************************************/
void  putEnglish(int x1, int y1,int ascii,int mx,int my,int color )
{
	char * English_save;                                /*����ָ����ģ��ȡ��ָ��*/

	int x0;                                           /*�����¼λ�õı�����*/
	int y0;
	int yt;
	int xt;

	int i = 0;                                            /*ѭ������*/
	int j = 0;
	int k = 0;
	unsigned char mask[] = { 0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01 };
	unsigned long offest;                            /*����Ӣ����ĸ�ں��ֿ��е�ƫ����*/
	FILE * fh;                                     /*����һ���ļ�ָ��*/
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

	x0 = x1;                                         /*��¼����λ��*/
	y0 = y1;
	fclose(fh);
	while (i <16)                                    /*ѭ���ж����Ӣ����ĸ*/
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

description :    ��ָ���ĵط��������

Input :          x1,y1 ���λ�����꣬Ϊ�����ĵ�ƫ����

out :           ��ָ��λ���������

*************************************************************/
void  putchinese(int x1, int y1, int neima, int color)
{

	FILE * fhzk_p;               /*�����ļ�ָ��*/

	char *mat;                                        /*�洢��ģ��ָ��*/

	int x, y;                                         /*λ�ô洢*/

	int i, j,k;                                         /*�򵥵�ѭ������*/
	char a[5];
	char qhs[3];
	char whs[3];
	unsigned char mask[] = { 0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01 };
	unsigned char qh, wh;
	unsigned long offset;

	fhzk_p = fopen("HZK\\hzk16", "rb");                         /*�򿪺��ֿ�*/

	if (fhzk_p == NULL)
	{
		printf("the hzk can't open\n");
		delay(1000);
		exit(1);
	}


	mat = (char *)malloc(32 * sizeof(char));                           /*�����ڴ�ռ�*/
	if (mat == NULL)
	{
		printf("there is no place\n");
		exit(1);
	}
	itoa(neima, a, 10);                                                /*�������λ��ֿ�*/
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

	offset = (94 * (qh - 1) + (wh - 1)) * 32L;                       /*����ƫ����*/
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

description :    ��ָ���ĵط��������뷨

Input :          x1,y1 ���λ�����꣬colorΪ���ֵ���ɫ

out :           ��ָ��λ���������

*************************************************************/

int  inputmethed(int x1, int y1,char * hanzi, int color)
{
	int count_num=0;
	int inix0;
	int *pxcur;
	int *pycur;
	int count = 0;                                              /*������λ*/
	int judge = 0;
	int pos = 0;                                         /*��¼ƴ����ƴ�����е�λ��*/
	int page = 1;
	int i = 0;                                                  /*��ѭ������*/
	int xcurr = x1;
	int ycurr = y1;
	int x_ying=x1;                                        /*��¼ʵʱλ��*/
	int y_ying=y1;
	int key;                                             /*��¼��ֵ*/
	Pinying  *thespe ;
	int asc;                         					   /*��¼ASCII��*/
	int n = 0;                                           /*��¼ƴ������*/
	char spellable[10] = { '\0'};                       /*�洢ƴ��*/
	thespe=(Pinying *)malloc(411*sizeof(Pinying));                                      /*����ƴ���ṹ*/
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
	oldint = getvect(0x1c);                               /*�����ж�*/

    inix0=x1;

	disable();
	setvect(0x1c, newint);
	enable();
	get_list(thespe);

	while (1)
	{
		key = bioskey(0);
		asc= key & 0x00ff;                                                    /*���ASCII��*/

		if ((('a' <= asc) && (asc <= 'z')) || (('1' <= asc) && (asc <= '9')) || (key == Backspace) || (key == BLANK) || (key == PLUS) || (key == MOUES)||(key==ENTER)||(key==ESC))   /*ȷ������Щ��ֵ*/
		{
			if ((asc>= 'a') && (asc<= 'z'))
			{
				page = 1;
				if (judge == 0)                                              /*���л���*/
				{
					put_case(xcurr, ycurr,&judge);
					judge = 1;
				}
				putEnglish(x_ying, y_ying+30, asc, 1, 1, 0xcece);                /*��ʾ�����ƴ��*/

				spellable[n++] =asc;                                        /*�洢�����ƴ��*/

				if (n >= 10)                                                  /*�����������ڹ���Ļ�*/
				{


						key = 0;
						asc =0;
						n++;                                                  /*������������������ѭ��*/
						continue;

				}

				if (search(thespe, spellable, &pos) == 0)
				{
					x_ying = x_ying +9;
					continue;
				}

				draw_pagechinese(xcurr, ycurr, thespe, pos, page,color);

			 }

			if (('1' <= asc) && (asc <= '5') || (key == BLANK))          /*�������������ּ������ǿո��*/
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
					else                                                 /*����洢�ĺ�������*/
					{
						count = 0;
						memset(hanzi, '\0', 40);
					}
					puthz(xcurr, ycurr, pos, asc, page,thespe, color);  /*��ָ���ĵط��������*/
				}
				else
				{
					if (count < 20)
					{
						savehanzi(pos, asc, page, hanzi, &count, thespe);
					}
					else                                                 /*����洢�ĺ�������*/
					{
						count = 0;
						memset(hanzi, '\0', 40);
					}
					puthz(xcurr, ycurr, pos, asc, page, thespe, color);  /*��ָ���ĵط��������*/
				}

                    count_num++;
					distoryboard(xcurr, ycurr,&judge);               /*������� */

					memset(spellable, '\0', 10);                          /*�����ĸ��*/


					xcurr = xcurr + 20;                                    /*�ƶ�����λ�ã�Ϊ��һ��������׼��*/
					*pxcur = xcurr;

					linever(xcurr - 21, ycurr, xcurr - 21, ycurr + 20, 2, 0x9490);   /*�������*/
					judge = 0;
					x_ying = xcurr;
					n = 0;
					pos = 0;
					page = 1;

					continue;
			}

			if ((key == PLUS) || (key == MOUES))                      /*������·�ҳ��*/
			{
				if (spellable[0] == '\0')
				{
					continue;
				}
				if (key == PLUS)                                      /*������·�ҳ*/
				{
					page++;
					//put_case(x1, y1, &judge, saveboard);       /*����ջ���*/
					draw_pagechinese(xcurr, ycurr, thespe, pos, page, color);
				}

				else                                                 /*������ǰ��·�ҳ�ϼ�*/
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
				if (spellable[0] != 0)                            /*��������*/
				{
					if (n >= 10)
					{
						n--;
					}
					else
					{
						spellable[n - 1] = '\0';
						n--;
						if (spellable[0]=='\0')                        /*����������һ������*/
						{
							distoryboard(xcurr, ycurr, &judge);        /*������� */
							n = 0;
							x_ying = xcurr;
						}

						else                                                     /*����������һ������*/
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

							//	put_case(x1, y1, &judge, saveboard);           /*����ջ���*/
							x_ying = xcurr + 9 * i;
							draw_pagechinese(xcurr, ycurr, thespe, pos, page, color);
						}
					}
					count_num--;
					continue;
				}

				else                                                     /*��������*/
				{
					xcurr = xcurr - 20;
					*pxcur = xcurr;
					linever(xcurr + 19, ycurr, xcurr +19, ycurr + 20, 2, 0x9490);   /*�������*/
					bar(xcurr, ycurr, xcurr + 20, ycurr + 20, 0x9490);
					count = count - 2;
					hanzi[count] = '\0';
					hanzi[count + 1] = '\0';
					x_ying = xcurr;
					count_num--;
					continue;
				}
			}


			if ((key == ESC)||(key==ENTER))                                          /*�˳����뷨*/
			{
			if (spellable[0] != '\0')
				{
					distoryboard(xcurr - 20, ycurr, &judge);               /*������� */
					free(thespe);
				}
             	free(thespe);
			   //	free(saveboard);
				break;
			}

			

	  }
	  x_ying = x_ying + 9;                                         /*yƴ��λ�ú���*/
   }
   

   
   setvect(0x1c, oldint);
   
   linever(xcurr, ycurr, xcurr, ycurr + 20, 2, 0xffff);   /*�������*/

   return 1;
  }



/**************************************************
function:       get_list

description :   �õ�ƴ�����е�����

Input :         spell_listΪ��Ӧ�Ľṹָ��

out��          ��

*************************************************************/

void  get_list(Pinying *spell_list)
{
	FILE  *fp;
	int i = 0;

	int str = 0;                                      /*�����м����*/
	char spell[10] = "\0";

	fp = fopen("pinyin.txt", "r");         /*���ļ�*/
	if (fp == NULL)
	{
		printf("the file can open\n");
		delay(1000);
		exit(1);
	}

	while (feof(fp) == 0)
	{
		fscanf(fp, "%s%d", spell, &str);                /*��ȡ����*/
		spell_list[i].neima = str;
		strcpy(spell_list[i].spell, spell);
		i++;
	}


	fclose(fp);                                        /*�ر��ļ�*/
}




/**************************************************
function:       put_case

description :   ��������Ŀ���

Input :         x_now ,y_now Ϊ�����λ�ã�savebo��ָ��洢֮ǰ������

out��          ��

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

description :   ��Ѱ�����ƴ����ƴ�������Ӧ��λ��

Input :         spell_listΪ�ṹָ��
				spellableΪ�洢ƴ���Ľṹ
				positionΪ��Ե�λ��

out��          ��

*************************************************************/

int  search(Pinying *spell_list, char *spellable, int * position)
{
	int i = 0;                                        /*ѭ������*/
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

description :   �ڿ�����ʾ��ƥ��ĺ���ѡ��

Input :


out��          ��

*************************************************************/
void draw_pagechinese(int x0, int y0, Pinying *spell_list, int hzpos, int page, int color)
{
	int i;
	int qwma1 = spell_list[hzpos].neima;                                        /*���ƴ����һ���ֵ���λ��*/
	int qwma2 = spell_list[hzpos + 1].neima;                                  /*��һ��ƴ����һ���ֵ���λ��*/
	int n;
	bar(x0, y0 + 58,x0+409,y0+90, 0xFF9D76);
	

	n = qwma2 - qwma1;                                                        /*�м��ж��ٺ���*/
	if ((page * 5) > n)                                                            /*������ֲ�����ʾһҳ��*/
	{
		n = qwma2 - qwma1 - (page - 1) * 5;
	}
	else
	{
		n = 5;
	}
	for (i = 0; i < n; i++)
	{
		putEnglish(x0+i*35, y0 + 63, 49 + i, 1, 1, color);             /*��ʾ�ֺ�*/

		putchinese(x0 + 20+i*34, y0 + 63, qwma1+(page-1)*5+i, color);

	}
}


/**************************************************
function:       puthz

description :   ������ĵط���ʾ��ѡ�ĺ���

Input :          x1,y1Ϊ�����λ�� positionΪƴ����Ӧλ�ã�
				 asciiΪ���������ASCII��
				 page Ϊ��ǰҳ��
				 spell_listΪ��Ӧ�ṹָ��
				 colorΪ��ɫ

out��


*************************************************************/

void puthz(int x1, int y1, int  position, int ascii, int page, Pinying *spell_list, int  color)
{

	int t = 0;                                              /*��ʾ��ѡ���ֺ�*/
	int qw = 0;
	t = ascii - '0';
	qw = spell_list[position].neima;

	putchinese(x1, y1, qw + (page - 1) * 5 + t-1, color);

}

/**************************************************
function:       put_word

description :   ������ĵط���ʾ�����Ӣ��

Input :          x1,y1Ϊ�����λ�� positionΪƴ����Ӧλ�ã�
				asciiΪ���������ASCII��
page Ϊ��ǰҳ��
spell_listΪ��Ӧ�ṹָ��
colorΪ��ɫ

out��


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

description :   �������뷨��ѡ�ֿ�

Input :         x0,y0Ϊ���뺺�ֵ�λ�ã�judeboָ���ж��Ƿ񻭿�ı�����
				savebo��ָ��洢֮ǰ������


out��          ��

*************************************************************/

void distoryboard(int x0, int y0,int *judebo)
{
	printf_image(x0, y0 + 30, x0 + 410, y0 + 94);
	*judebo = 0;

}

/**************************************************
function:       savehanzi

description :   �洢���뷨����ĺ���

Input :


out��          ��

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
	itoa(neima, a, 10);                                                /*�������λ��ֿ�*/
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

description :   �������뷨��ѡ�ֿ�

Input :         x0,y0Ϊ����Ӣ�ĺ����ֵ�λ�ã�judeboָ���ж��Ƿ񻭿�ı�����
                    


out��          ��

*************************************************************/

void  inputEnglish(int x1, int y1, char * mima,int color)
{

	int xcurr=x1;
	int ycurr=y1;
	int *px;
	int *py;
	int key;                                             /*��¼��ֵ*/
	int asc;                                             /*��¼ASCII��*/
	int count = 0;
	memset(mima,'\0',16);                   /*�洢�����ڵ���ͼ��*/
	px = quanxcurr();
	py = quanycurr();

	*px = xcurr;
	*py = ycurr;

	oldint = getvect(0x1c);                               /*�����ж�*/
	disable();
	setvect(0x1c, newint);
	enable();
	while (1)
	{
		key = bioskey(0);
		asc = key & 0x00ff;                                                    /*���ASCII��*/
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

description :   �˶����������Ϣ�ǲ��Ǻ��ļ��е�һ��

Input :         



out��          �����Ϣһ�·���1�����򷵻�0

*************************************************************/

int checkover(char * mima, const char * fname)
{
	FILE *fp;                     /*�����ļ�ָ��*/
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

description :   ����Ҫ��д����Ϣ��д���ļ���

Input :          



out��          �����Ϣһ�·���1�����򷵻�0

*************************************************************/

void  check_in(char * mima, const char * fname)
{
	FILE *fp;                                        /*�����ļ�ָ��*/

	fp = fopen(fname, "wt");
	if (fp == NULL)
	{
		printf("the file can not open\n");
		exit(1);
	}

	fprintf(fp, "%s", mima);
	fclose(fp);
}
