#include"main.h"


/*结构体包涵：按键的键值与代表的字符*/
typedef struct    
{
  int value;
  char ch;
}setKeyValue;


/*该数组收集了26个英文字母的大小写以及上、右数字键所对应的键值*/
setKeyValue KeyValue[74]={
	{0x1e61,'a'},{0x3062,'b'},{0x2e63,'c'},{0x2064,'d'},{0x1265,'e'},
	{0x2166,'f'},{0x2267,'g'},{0x2368,'h'},{0x1769,'i'},{0x246a,'j'},
	{0x256b,'k'},{0x266c,'l'},{0x326d,'m'},{0x316e,'n'},{0x186f,'o'},
	{0x1970,'p'},{0x1071,'q'},{0x1372,'r'},{0x1f73,'s'},{0x1474,'t'},
	{0x1675,'u'},{0x2f76,'v'},{0x1177,'w'},{0x2d78,'x'},{0x1579,'y'},
	{0x2c7a,'z'},
	{0x1e41,'A'},{0x3042,'B'},{0x2e43,'C'},{0x2044,'D'},{0x1245,'E'},
	{0x2146,'F'},{0x2247,'G'},{0x2348,'H'},{0x1749,'I'},{0x244a,'J'},
	{0x254b,'K'},{0x264c,'L'},{0x324d,'M'},{0x314e,'N'},{0x184f,'O'},
	{0x1950,'P'},{0x1051,'Q'},{0x1352,'R'},{0x1f53,'S'},{0x1454,'T'},
	{0x1655,'U'},{0x2f56,'V'},{0x1157,'W'},{0x2d58,'X'},{0x1559,'Y'},
	{0x2c5a,'Z'},
	{0x4f31,'1'},{0x5032,'2'},{0x5133,'3'},{0x4b34,'4'},{0x4c35,'5'},
	{0x4d36,'6'},{0x4737,'7'},{0x4838,'8'},{0x4939,'9'},{0x5230,'0'},
	{0x231,'1'},{0x332,'2'},{0x433,'3'},{0x534,'4'},{0x635,'5'},
	{0x736,'6'},{0x837,'7'},{0x938,'8'},{0xa39,'9'},{0xb30,'0'},{0x532e,'.'},
    {0x342e,'.'} };


/*
    补充几个功能键的键值：
	backspace:0xe08
	esc:0x11b
	enter:0x1c0d
	上方向键：0x4800
	下方向键：0x5000
	左方向键：0x4b00
	右方向键：0x4d00

 */









/*************************************************
Function: searchKeyValue
Description: 根据键值返回表中其对应字符
Calls: 
Return: 若有则返回对应字符；若表中无此键值，则返回'\0'
*************************************************/
char searchKeyValue(int value)   
{
  int i;
  for(i=0;i<74;i++)
  {
	if(value==KeyValue[i].value)break;
  }
  if(i<74)return KeyValue[i].ch;
  else return '\0';
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


void outtextxy(int x,int y,char *c,int mx,int my,int mar,int color)//间隔自定义，大小自定义
{
	int a;
	char *p=c;
	while(*p!='\0')
	{
		a = (int)(*p);
		putEnglish(x,y,a,mx,my,color);
		p++;
		x+=mar;
	}
}

int input_me(int *x,int *y,int mode,char *account,char *code)
{
	int key;
	int i=0;//用于计算已输入字符数目
	char *p;//输入字符的中间指针变量
	char ch;//用于临时储存键值所对应字符的变量
	int buttons,judge;
	char temp[2] = {'\0','\0'};
	if(mode==1)
	{
		p = code;
	}
	else{
		p = account;
	}
	while(*p != '\0')
	{
		i++;
		p++;
	}
    while(1)
	{
		newxy(x,y,&buttons);
		key=0;
		if (kbhit() != 0)
		{
			key = bioskey(0);
		}
		if(key ==0xe08)
	    {
		    if(p != code)
		    {
			    bar(290 + i * 18, 195, 310 + i * 18, 213,65535);
			    p--;
			    i--;
		    }
			*p = '\0';
	    }
		
		if(*x>=200&&*x<=400&&*y<=675&&*y>=525&&buttons)
		{

			/*
			yanzheng
			*/
			return 1;
		}
		
		if(*x>=300&&*x<=700&&*y>=325&&*y<=375&&buttons)
		{
			judge = input_me(x,y,1,account,code);
			return judge;
		}
		
		
	/*将按键对应的字符存入accounts数组中*/
	    ch = searchKeyValue(key);
	    if (ch != '\0'&&i<10)
	    {
		    if(mode==1)
		    {
		    //bar(250 + i * 11, 218, 261 + i * 11, 242,65535);
            FillCircle(312+i*25,350,8,0);
		    }
		/*画一个圆*/
            else
		    {
				temp[0] = ch;
			    outtextxy(300+i*18,195,temp,2,1,10,0);
		    }




		/*将字符存入数组中*/
		    *p = ch;
		    p++;
		    *p = '\0';
		    i++;
	    }
	}
}