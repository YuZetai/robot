#ifndef __HANZI
#define __HANZI

#include<stdio.h>
#include<fcntl.h>
#include<io.h>
#include<stdlib.h>

#define THICK 1
#define THIN 0
#define CLOSE_ZIKU 2
#define HZ_SIZE 16

extern int openZiKu(int thick);
extern void getMat(char incode[],char bytes[],int thick);
extern void showHanZi16(int x0,int y0,char incode[],int color,int thick);
extern void showHanZiBySize(int x0,int y0,char incode[],int color,int thick,int size);
extern void closeZiKu();
#endif