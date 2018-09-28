#ifndef flame.h
#define flame.h

typedef struct{
	int sign;//sign up=0,sign in=1;
	int sign_up_case;//had not=2,success=1,fail=0;
	int sign_box;//had not=2,id=0,password=1;
}LOADING;

extern void load_page();

extern int enterpage();

extern void zhuce_page();

extern int mainpage();

#endif