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
Function：		quanxcurr

Description：	  得到输入横坐标


Calls：

Called By：

Input：			

Output：		

Return：	    None

Others：		None
**********************************************************/
extern int * quanxcurr();


/**********************************************************
Function：		quanycurr

Description：	  得到输入纵坐标


Calls：

Called By：

Input：

Output：

Return：	    None

Others：		None
**********************************************************/

extern int * quanycurr();






/**********************************************************
Function：		  interrupt newint

Description：	  光标中断函数


Calls：

Called By：

Input：

Output：

Return：	    None

Others：		None
**********************************************************/

extern   void interrupt newint(unsigned bp, unsigned di, unsigned si, unsigned ds, unsigned es, unsigned dx, unsigned cx, unsigned bx, unsigned ax, unsigned ip, unsigned cs, unsigned flags);


/**********************************************************
Function：		put_English

Description：	  在指定的地方输出英文


Calls：

Called By：

Input：			x1,y1 输出位置坐标，ascii为该英文的ASCII码

Output：		在指定位置输出英文字母

Return：	    None

Others：		None
**********************************************************/
extern void putEnglish(int x1, int y1, int ascii, int mx, int my, int color);



/**********************************************************
Function：		putchinese

Description：	在指定的地方打出一个汉字


Calls：

Called By：

Input：			x1,y1 输出位置坐标，neima为该汉字的内码，color为所要输出的颜色

Output：        在指定位置输出汉字		

Return:         None

Others：		None
**********************************************************/
extern  void putchinese(int x1, int y1, int  neima, int color);

/**********************************************************
Function：		get_list

Description：	得到拼音库中的内容

Calls：         

Called By：      imputmethod

Input：			spell_list为相应的结构指针

Output：        在指定位置输出汉字

Return : None

Others：		None
***********************************************************/
extern  void  get_list(Pinying *spell_list);


/**********************************************************
Function：		 put_case

Description：	画出输入的框子

Calls：

Called By：      imputmethod

Input：			  x_now ,y_now 为画框的位置，savebo是指向存储之前的区域
Output：        在指定位置输出汉字
 
Return :        None

Others：		None
***********************************************************/
extern   void  put_case(int x_now, int y_now, int *judge0);


/**********************************************************
Function：	    search

Description：	寻找拼音中的对应项

Calls：

Called By：      imputmethod

Input：			 
Return :        找到了就是1，没找到就是0

Others：		None
***********************************************************/
extern int  search(Pinying *spell_list, char *spellable, int * position);



/*********************************************************
Function：		 draw_pagechinese

Description：	在框内显示出匹配的汉字选项

Calls：

Called By：      imputmethod

Input：			 x0,y0为画框的位置，spell_list为结构指针 hzpos为对应位置
                 page为页数，color为颜色

Output：         在指定位置画出框        

Return :        None

Others：		None
***********************************************************/

extern void draw_pagechinese(int x0, int y0, Pinying *spell_list, int hzpos, int page, int color);


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

extern void puthz(int x1, int y1, int  position, int ascii, int page, Pinying *spell_list, int  color);



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
extern  void put_word(int x0, int y0, char * spell, int color);




/**************************************************
function:       distoryboard

description :   消除输入法的选字框

Input :         x0,y0为输入汉字的位置，judebo指向判断是否画框的变量，
				savebo是指向存储之前的区域


out：          无

*************************************************************/

extern void distoryboard(int x0, int y0, int *judebo);




/**************************************************
function:       inputmethod

description :    在指定的地方进行输入法

Input :          x1,y1 输出位置坐标，color为汉字的颜色

out :           在指定位置输出文字

*************************************************************/

extern int  inputmethed(int x1, int y1, char * hanzi, int color);

/**************************************************
function:       savehanzi

description :   存储输入法输出的汉字

Input :


out：          无

*************************************************************/

 extern  void savehanzi(int  position, int ascii, int page, char * hanzi, int * count, Pinying *spell_list);


 /**************************************************
 function:       inputEnglish

 description :   消除输入法的选字框

 Input :         x0,y0为输入英文和数字的位置，judebo指向判断是否画框的变量，



 out：          无

 *************************************************************/

 extern void  inputEnglish(int x1, int y1, char * mima, int color);



 /**************************************************
 function:       check_out

 description :   核对所输入的信息是不是和文件中的一致

 Input :



 out：          如果信息一致返回1，否则返回0

 *************************************************************/

 extern int checkover(char * mima, const char * fname);




 /**************************************************
 function:        check_in

 description :   将所要填写的信息填写到文件中

 Input :



 out：          如果信息一致返回1，否则返回0

 *************************************************************/

 extern void  check_in(char * mima, const char * fname);


#endif