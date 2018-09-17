#ifndef advancegf.h
#define advancegf.h

extern void Fillellipse(int x1,int y1,int x2,int y2,int r,int color);

extern void ellipse(int x1,int y1,int x2,int y2,int r,int color);

extern void semicircle_up(int x,int y,int r,int color);

extern void semicircle_down(int x,int y,int r,int color);

extern void bow(int x0,int y0,int r,int color);

extern void fill_bow_right_up(int x,int y,int r,int color);

extern void fill_bow_left_up(int x,int y,int r,int color);

extern void fill_bow_left_down(int x,int y,int r,int color);

extern void fill_bow_right_down(int x,int y,int r,int color);

extern void fill_bow_down(int x,int y,int r, int color);

extern void fill_bow_left(int x,int y, int r, int color);

extern void fill_bow_right(int x,int y,int r,int color);

extern void bar_round(int x,int y,int length,int height,int r,int thick,int color);

extern void bar_round_with_shadow(int x,int y,int length,int height,int r,int thick,int color);

extern void bow_right_down(int x,int y,int r,int color);

extern void bow_left_down(int x,int y,int r,int color);

extern void bow_right_up(int x,int y,int r,int color);

extern void bow_left_up(int x,int y,int r,int color);

#endif