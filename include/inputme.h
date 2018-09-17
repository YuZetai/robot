#ifndef _inputme_h_
#define _inputme_h_


#include"SVGAhead.h"
#include<stdio.h>
#include<stdlib.h>
#include"hzxs.h"
#include<bios.h>
#include<string.h>

#define  Backspace   0x0e08
#define  BLANK       0x3920
#define  ENTER       0x1c0d
#define  ESC         0x011b
#define  PLUS        0x0d3d
#define  MOUES       0x0c2d
#define  UP          0x4800
#define  DOWN        0X5000

typedef struct       
{
	char spell[10];
	int neima;
}Pinying;


/**********************************************************
Function��		quanxcurr

Description��	  �õ����������


Calls��

Called By��

Input��			

Output��		

Return��	    None

Others��		None
**********************************************************/
extern int * quanxcurr();


/**********************************************************
Function��		quanycurr

Description��	  �õ�����������


Calls��

Called By��

Input��

Output��

Return��	    None

Others��		None
**********************************************************/

extern int * quanycurr();






/**********************************************************
Function��		  interrupt newint

Description��	  ����жϺ���


Calls��

Called By��

Input��

Output��

Return��	    None

Others��		None
**********************************************************/

extern   void interrupt newint(unsigned bp, unsigned di, unsigned si, unsigned ds, unsigned es, unsigned dx, unsigned cx, unsigned bx, unsigned ax, unsigned ip, unsigned cs, unsigned flags);


/**********************************************************
Function��		put_English

Description��	  ��ָ���ĵط����Ӣ��


Calls��

Called By��

Input��			x1,y1 ���λ�����꣬asciiΪ��Ӣ�ĵ�ASCII��

Output��		��ָ��λ�����Ӣ����ĸ

Return��	    None

Others��		None
**********************************************************/
extern void putEnglish(int x1, int y1, int ascii, int mx, int my, int color);



/**********************************************************
Function��		putchinese

Description��	��ָ���ĵط����һ������


Calls��

Called By��

Input��			x1,y1 ���λ�����꣬neimaΪ�ú��ֵ����룬colorΪ��Ҫ�������ɫ

Output��        ��ָ��λ���������		

Return:         None

Others��		None
**********************************************************/
extern  void putchinese(int x1, int y1, int  neima, int color);

/**********************************************************
Function��		get_list

Description��	�õ�ƴ�����е�����

Calls��         

Called By��      imputmethod

Input��			spell_listΪ��Ӧ�Ľṹָ��

Output��        ��ָ��λ���������

Return : None

Others��		None
***********************************************************/
extern  void  get_list(Pinying *spell_list);


/**********************************************************
Function��		 put_case

Description��	��������Ŀ���

Calls��

Called By��      imputmethod

Input��			  x_now ,y_now Ϊ�����λ�ã�savebo��ָ��洢֮ǰ������
Output��        ��ָ��λ���������
 
Return :        None

Others��		None
***********************************************************/
extern   void  put_case(int x_now, int y_now, int *judge0);


/**********************************************************
Function��	    search

Description��	Ѱ��ƴ���еĶ�Ӧ��

Calls��

Called By��      imputmethod

Input��			 
Return :        �ҵ��˾���1��û�ҵ�����0

Others��		None
***********************************************************/
extern int  search(Pinying *spell_list, char *spellable, int * position);



/*********************************************************
Function��		 draw_pagechinese

Description��	�ڿ�����ʾ��ƥ��ĺ���ѡ��

Calls��

Called By��      imputmethod

Input��			 x0,y0Ϊ�����λ�ã�spell_listΪ�ṹָ�� hzposΪ��Ӧλ��
                 pageΪҳ����colorΪ��ɫ

Output��         ��ָ��λ�û�����        

Return :        None

Others��		None
***********************************************************/

extern void draw_pagechinese(int x0, int y0, Pinying *spell_list, int hzpos, int page, int color);


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

extern void puthz(int x1, int y1, int  position, int ascii, int page, Pinying *spell_list, int  color);



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
extern  void put_word(int x0, int y0, char * spell, int color);




/**************************************************
function:       distoryboard

description :   �������뷨��ѡ�ֿ�

Input :         x0,y0Ϊ���뺺�ֵ�λ�ã�judeboָ���ж��Ƿ񻭿�ı�����
				savebo��ָ��洢֮ǰ������


out��          ��

*************************************************************/

extern void distoryboard(int x0, int y0, int *judebo);




/**************************************************
function:       inputmethod

description :    ��ָ���ĵط��������뷨

Input :          x1,y1 ���λ�����꣬colorΪ���ֵ���ɫ

out :           ��ָ��λ���������

*************************************************************/

extern int  inputmethed(int x1, int y1, char * hanzi, int color);

/**************************************************
function:       savehanzi

description :   �洢���뷨����ĺ���

Input :


out��          ��

*************************************************************/

 extern  void savehanzi(int  position, int ascii, int page, char * hanzi, int * count, Pinying *spell_list);


 /**************************************************
 function:       inputEnglish

 description :   �������뷨��ѡ�ֿ�

 Input :         x0,y0Ϊ����Ӣ�ĺ����ֵ�λ�ã�judeboָ���ж��Ƿ񻭿�ı�����



 out��          ��

 *************************************************************/

 extern void  inputEnglish(int x1, int y1, char * mima, int color);



 /**************************************************
 function:       check_out

 description :   �˶����������Ϣ�ǲ��Ǻ��ļ��е�һ��

 Input :



 out��          �����Ϣһ�·���1�����򷵻�0

 *************************************************************/

 extern int checkover(char * mima, const char * fname);




 /**************************************************
 function:        check_in

 description :   ����Ҫ��д����Ϣ��д���ļ���

 Input :



 out��          �����Ϣһ�·���1�����򷵻�0

 *************************************************************/

 extern void  check_in(char * mima, const char * fname);


#endif