#ifndef advancegf.h
#define advancegf.h

/**************************************************
function:        Fillellipse

description:     填充椭圆（仅限竖直方向）

Input:           x1,y1(上方圆心坐标),x2,y2(下方圆心坐标),r(两圆半径),color;

out:             一个由上下两个填充圆形和一个矩形连接而成的椭圆
**************************************************************/
extern void Fillellipse(int x1,int y1,int x2,int y2,int r,int color);

/**************************************************
function:        ellipse

description:     椭圆（仅限竖直方向）

Input:           x1,y1(上方圆心坐标),x2,y2(下方圆心坐标),r(两圆半径),color;

out:             由上下两个半圆和两条直线连接而成的椭圆

quote:           semicircle_up,semicircle_down;
**************************************************************/
extern void ellipse(int x1,int y1,int x2,int y2,int r,int color);

/**************************************************
function:        semicircle_up

description:     上半圆（非填充）

Input:           x,y,r,color;

out:             一个上半圆（非实心）
**************************************************************/
extern void semicircle_up(int x,int y,int r,int color);

/**************************************************
function:        semicircle_down

description:     下半圆（非填充）

Input:           x,y,r,color;

out:             一个下半圆（非实心）
**************************************************************/
extern void semicircle_down(int x,int y,int r,int color);

/**************************************************
function:        bow

description:     此函数是专为机器人正面嘴巴的绘制设计，生成一个弧度为pi/6的下圆弧

Input:           x0,y0,r,color;

out:             弧度pi/6的下圆弧
**************************************************************/
extern void bow(int x0,int y0,int r,int color);

/**************************************************
function:        fill_bow_right_up

description:     右上填充扇形

Input:           x,y,r,color;

out:             右上角1/4扇形
**************************************************************/
extern void fill_bow_right_up(int x,int y,int r,int color);

/**************************************************
function:        fill_bow_left_up

description:     左上填充扇形

Input:           x,y,r,color;

out:             左上角1/4扇形
**************************************************************/
extern void fill_bow_left_up(int x,int y,int r,int color);

/**************************************************
function:        fill_bow_left_down

description:     左下填充扇形

Input:           x,y,r,color;

out:             左下角1/4扇形
**************************************************************/
extern void fill_bow_left_down(int x,int y,int r,int color);

/**************************************************
function:        fill_bow_right_down

description:     右下填充扇形

Input:           x,y,r,color;

out:             右下角1/4扇形
**************************************************************/
extern void fill_bow_right_down(int x,int y,int r,int color);

/**************************************************
function:        fill_bow_down

description:     下填充扇形

Input:           x,y,r,color;

out:             下1/4扇形
**************************************************************/
extern void fill_bow_down(int x,int y,int r, int color);

/**************************************************
function:        fill_bow_left

description:     下填充扇形

Input:           x,y,r,color;

out:             左1/4扇形
**************************************************************/
extern void fill_bow_left(int x,int y, int r, int color);

/**************************************************
function:        fill_bow_right

description:     下填充扇形

Input:           x,y,r,color;

out:             右1/4扇形
**************************************************************/
extern void fill_bow_right(int x,int y,int r,int color);

/**************************************************
function:        bar_round

description:     圆角矩形

Input:           x,y(矩形中心坐标),length(矩形长度),height(矩形高度),r(圆角半径),thick(线段粗,目前只能改变直线段粗细-09/25),color;

out:             圆角半径可变，线粗可变的圆角矩形

quote:           fill_bow_right_down,fill_bow_right_up,fill_bow_left_down,fill_bow_left_up,bow_right_up,bow_right_down,bow_left_up,bow_left_down;
**************************************************************/
extern void bar_round(int x,int y,int length,int height,int r,int thick,int color);

/**************************************************
function:        bar_round_with_shadow

description:     带阴影效果的圆角矩形

Input:           x,y(矩形中心坐标),length(矩形长度),height(矩形高度),r(圆角半径),thick(线段粗,目前只能改变直线段粗细-09/25),color;

out:             圆角半径可变，线粗可变的带阴影（阴影大小与线粗有关）圆角矩形

quote:           fill_bow_right_down,fill_bow_right_up,fill_bow_left_down,fill_bow_left_up,bow_right_up,bow_right_down,bow_left_up,bow_left_down;
**************************************************************/
extern void bar_round_with_shadow(int x,int y,int length,int height,int r,int thick,int color);

/**************************************************
function:        bow_right_down

description:     右下扇形

Input:           x,y,r,color;

out:             右下1/4扇形（非填充）
**************************************************************/
extern void bow_right_down(int x,int y,int r,int color);

/**************************************************
function:        bow_left_down

description:     左下扇形

Input:           x,y,r,color;

out:             左下1/4扇形（非填充）
**************************************************************/
extern void bow_left_down(int x,int y,int r,int color);

/**************************************************
function:        bow_right_up

description:     右上扇形

Input:           x,y,r,color;

out:             右上1/4扇形（非填充）
**************************************************************/
extern void bow_right_up(int x,int y,int r,int color);

/**************************************************
function:        bow_left_up

description:     左上扇形

Input:           x,y,r,color;

out:             左上1/4扇形（非填充）
**************************************************************/
extern void bow_left_up(int x,int y,int r,int color);

/**************************************************
function:        lean_line

description:     倾斜直线

Input:           x,y(直线起点坐标),length(线长),theta,color;

out:             倾斜直线

quote:           
**************************************************************/
extern void lean_line(int x,int y,int length,int theta,int color);

/**************************************************
function:        lean_line_thick

description:     线粗可变的倾斜直线

Input:           x,y(直线起点坐标),length(线长),theta,thick,color;

out:             线粗可变的倾斜直线

quote:           lean_line
**************************************************************/
extern void lean_line_thick(int x,int y,int length,int theta,int thick,int color);

/**************************************************
function:        theta_bar

description:     倾斜矩形(实质是用倾斜直线平移形成的平行四边形),但目前在45-90度区域输出不连续-09/25

Input:           x,y(矩形左上角点坐标),length(矩形边长),height(矩形高度),theta,color;

out:             倾斜矩形

quote:           lean_line_thick
**************************************************************/
extern void theta_bar(int x,int y,int length,int height,int theta,int color);

/**************************************************
function:        robot_hand

description:     机器人的手,但目前在45-90度区域输出不连续-09/25

Input:           x,y,theta;

out:             图形

quote:           theta_bar,FillCircle
**************************************************************/
extern void robot_hand(int x,int y,int theta);

#endif