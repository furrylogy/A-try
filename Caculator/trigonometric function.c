#define  _CRT_SECURE_NO_WARNINGS
#include"major function.h"
#define $ 3.1415926//用$代替π
void sin0();
void cos0();
void tan0();
void trigonometric2();
void trigonometric1();
double chang();
void trigonometric2() {
	int a; double b;
	printf("当前的单位为度\n");
	printf("请选择要计算的三角函数\n");
	printf("0.更换单位为弧度   1.sin   2.cos   3.tan   \n");
	scanf("%d", &a);
	switch (a) {
	case 0:trigonometric1(); return;
	case 1:printf("请输入数据\n"); scanf("%lf", &b); b = chang(b); sin0(b); return;
	case 2:printf("请输入数据\n"); scanf("%lf", &b); b = chang(b); cos0(b); return;
	case 3:printf("请输入数据\n"); scanf("%lf", &b); b = chang(b); tan0(b); return;
	}
}
void trigonometric1() {
	int a; double b;
	printf("*******************************************\n");
	printf("当前的单位为弧度(不需要输入π)(请不要输入分数(ó﹏ò)如0.5请不要输入为1/2)\n");
	printf("请选择要计算的三角函数\n");
	printf("0. 更换单位为度   1.sin   2.cos   3.tan   \n");
	scanf("%d", &a);
	switch (a) {
	case 0:trigonometric2(); return;
	case 1:printf("请输入数据\n"); scanf("%lf", &b); sin0(b); return;
	case 2:printf("请输入数据\n"); scanf("%lf", &b); cos0(b ); return;
	case 3:printf("请输入数据\n"); scanf("%lf", &b);  tan0(b ); return;
	}
}


void sin0(double a) {
	double  b; char re[100];
	b = sin(a*$);
	printf("sin(%lfπ)=%lf\n", a, b);
	sprintf(re, "sin(%lfπ)=%lf\n", a, b);
	fileadd(re);
}
void cos0(double a) {
	double  b; char re[100];
	b = cos(a*$);
	printf("con(%lfπ)=%lf\n", a, b);
	sprintf(re, "con(%lfπ)=%lf\n", a, b);
	fileadd(re);
}
void tan0(double a) {
	double  b; char re[100];
	if ((int)(2 * a) % 2 != 0) {
		printf("无法计算\n");
		return;
	}
	else {
		b = tan(a*$);

		printf("tan(%lfπ)=%lf\n", a, b);
		sprintf(re, "tan(%lfπ)=%lf\n", a, b);
		fileadd(re);
	}
}
double chang(double b) {
	return (b / 180);
}