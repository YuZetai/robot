#ifndef __MOVE_H
#define __MOVE_H

typedef struct{
	int leg;//左脚动为1，右脚动为0；
	int leg_left;
	int leg_right;//用于传入moveaim的参数，改变脚的矩形大小，使两个脚看起来像在走。
	unsigned int *cat;//存储其图像信息
	int x;
	int y;
}ROBOT_CASE;
extern void movedown(ROBOT_CASE *);
extern void moveup(ROBOT_CASE *);
extern void moveright(ROBOT_CASE *);
extern void moveleft(ROBOT_CASE *);
#endif