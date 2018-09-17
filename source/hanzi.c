#include"hanzi.h"
#include"svgahead.h"

int openZiKu(int thick){
	static int ziku=-1;
	if(thick==CLOSE_ZIKU){
		ziku=-1;
		return -1;
	}
	if(ziku==-1){
		if(thick==THICK){
			ziku=open("c:\\cph\\robot\\ziku_cu.txt",O_BINARY|O_RDONLY);
		}else {
			ziku=open("c:\\cph\\robot\\ziku.txt",O_BINARY|O_RDONLY);	
		}
		if(ziku==-1){
			printf("the ziku file can not be opened");
			exit(1);
		}
	}
	
	//lseek(ziku,0,SEEK_SET);
	return ziku;
}

void closeZiKu(){
	int ziku;
	if(ziku==-1)return;
	close(ziku);
	openZiKu(CLOSE_ZIKU);
}

void getMat(char incode[],char bytes[],int thick){
	unsigned char qh,wh;
	unsigned long offset;
	int ziku=openZiKu(thick);
	qh=incode[0]-0xa0;
	wh=incode[1]-0xa0;
	offset=(94*(qh-1)+wh-1)*32L;
	lseek(ziku,offset,SEEK_SET);
	read(ziku,bytes,32);
	//close(ziku);
}

void showHanZi16(int x0,int y0,char incode[],int color,int thick){
	unsigned char mask[]={0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};
	int i,j,x,y,pos;
	char mat[32];
	getMat(incode,mat,thick);
	y=y0;
	for(i=0;i<16;i++){
		x=x0;
		pos=2*i;
		for(j=0;j<16;j++){
			if((mask[j%8]&mat[pos+j/8])!=NULL){
				putpixel(x,y,color);
			}
			x++;
		}
		y++;
	}
}

void showHanZiBySize(int x0,int y0,char incode[],int color,int thick,int size){
	unsigned char mask[]={0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};
	int i,j,x,y,pos,num=16*size;
	char mat[32];
	getMat(incode,mat,thick);
	y=y0;
	for(i=0;i<num;i++){
		x=x0;
		pos=2*(i/size);
		for(j=0;j<num;j++){
			if((mask[(j/size)%8]&mat[pos+j/(8*size)])!=NULL){
				putpixel(x,y,color);
			}
			x++;
		}
		y++;
	}
}