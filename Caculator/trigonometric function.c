#define  _CRT_SECURE_NO_WARNINGS
#include"major function.h"
#define $ 3.1415926//��$�����
void sin0();
void cos0();
void tan0();
void trigonometric2();
void trigonometric1();
double chang();
void trigonometric2() {
	int a; double b;
	printf("��ǰ�ĵ�λΪ��\n");
	printf("��ѡ��Ҫ��������Ǻ���\n");
	printf("0.������λΪ����   1.sin   2.cos   3.tan   \n");
	scanf("%d", &a);
	switch (a) {
	case 0:trigonometric1(); return;
	case 1:printf("����������\n"); scanf("%lf", &b); b = chang(b); sin0(b); return;
	case 2:printf("����������\n"); scanf("%lf", &b); b = chang(b); cos0(b); return;
	case 3:printf("����������\n"); scanf("%lf", &b); b = chang(b); tan0(b); return;
	}
}
void trigonometric1() {
	int a; double b;
	printf("*******************************************\n");
	printf("��ǰ�ĵ�λΪ����(����Ҫ�����)(�벻Ҫ�������(���n��)��0.5�벻Ҫ����Ϊ1/2)\n");
	printf("��ѡ��Ҫ��������Ǻ���\n");
	printf("0. ������λΪ��   1.sin   2.cos   3.tan   \n");
	scanf("%d", &a);
	switch (a) {
	case 0:trigonometric2(); return;
	case 1:printf("����������\n"); scanf("%lf", &b); sin0(b); return;
	case 2:printf("����������\n"); scanf("%lf", &b); cos0(b ); return;
	case 3:printf("����������\n"); scanf("%lf", &b);  tan0(b ); return;
	}
}


void sin0(double a) {
	double  b; char re[100];
	b = sin(a*$);
	printf("sin(%lf��)=%lf\n", a, b);
	sprintf(re, "sin(%lf��)=%lf\n", a, b);
	fileadd(re);
}
void cos0(double a) {
	double  b; char re[100];
	b = cos(a*$);
	printf("con(%lf��)=%lf\n", a, b);
	sprintf(re, "con(%lf��)=%lf\n", a, b);
	fileadd(re);
}
void tan0(double a) {
	double  b; char re[100];
	if ((int)(2 * a) % 2 != 0) {
		printf("�޷�����\n");
		return;
	}
	else {
		b = tan(a*$);

		printf("tan(%lf��)=%lf\n", a, b);
		sprintf(re, "tan(%lf��)=%lf\n", a, b);
		fileadd(re);
	}
}
double chang(double b) {
	return (b / 180);
}