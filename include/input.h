#ifndef input.h
#define input.h





extern void putEnglish(int x,int y,int asc,int mx,int my,int color);

extern void outtextxy(int x,int y,char *c,int mx,int my,int mar,int color);

extern int input_me(int *x,int *y,int mode,char *account,char *code);

extern char searchKeyValue(int value);
#endif