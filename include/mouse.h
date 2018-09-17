#ifndef mouse.h
#define mouse.h

#define xmax 1023
#define xmin 1
#define ymax 767
#define ymin 1

extern void drawmouse(int x,int y);
extern int init();
extern int getfun(int *mx,int *my,int *mbutt);
extern void movemouse(int *mx,int *my,int *mbutt,unsigned int *mousesave);
extern void reset_mouse(int *,int *,unsigned int *mousesave);

#endif