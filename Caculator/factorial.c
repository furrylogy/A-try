#define  _CRT_SECURE_NO_WARNINGS
#include"major function.h"
void factorial0();
void Combination_Number_Formula();
void permutation();
void Combination_Number_Formula();
void factorial() {
	int a;
	printf("请选择要计算的方式\n");
	printf("1.阶乘2.组合数3.排列数\n");
	scanf("%d", &a);
	switch (a) {
	case 1:factorial0(); break;
	case 2:Combination_Number_Formula(); break;
	case 3:permutation(); break;
	}
}
void factorial0() {
	printf("请输入数字\n"); 
	int a; unsigned long long n = 1; char an[1000]; sprintf(an, "%d", 1); char num1[100]; char num2[1000]; char re[1000];
	scanf("%d", &a);
	if (a < 0) {
		printf("数字不合法\n");
		factorial0(); return;
	}
	if (a < 12) {
		for (int i = 1; i <= a; i++) {
			n *= i;
		}
		sprintf(re, "%d的阶乘是%lld\n",a, n);
		printf("%s", re);
		fileadd(re);
	}
	if (a >= 12) {
		for (int i = 1; i <= a; i++) {
			sprintf(num1, "%d", i);   strcpy(num2, an);
			bigNumberMultiply(num1, num2, an);
		}sprintf(re,"%d的阶乘是%s\n", a,an);
		printf("%s", re);
		fileadd(re);
	}
}
void Combination_Number_Formula() {
	printf("请输入两个数字，前面的在上，后面的在下\n");
	int a; int b; unsigned long long an = 1; unsigned long long an1 = 1; unsigned long long an2 = 1;
	char re[1000];
	scanf("%d%d", &a, &b);
	if (a < 0 || b < 0 || a>b) {
		printf("输入不合法\n");
		Combination_Number_Formula();
	}
	for (int i = b; i > (b - a); i--) {
		an1 = i * an1;
	}
	for (int i = 1; i <= a; i++) {
		an2 *= i;
	}
	an = (an1 / an2);
	sprintf(re,"C%d %d为%lld",a,b, an);
	printf("%s", re);
	fileadd(re);
}
void permutation() {
	printf("请输入两个数字，前面的在上，后面的在下\n");
	int a; int b; unsigned long long an = 1; char re[1000];
	scanf("%d", &a); scanf("%d", &b);
	if (a < 0 || b < 0||a>b) {
		printf("输入不合法\n");
		permutation();
	}
	for (int i = b; i > (b - a); i--) {
		an = i * an;
	}
	sprintf(re,"A%d %d为%lld\n", an);
	printf("%s", re);
	fileadd(re);
}