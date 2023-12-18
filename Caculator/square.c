#define  _CRT_SECURE_NO_WARNINGS
#include "major function.h"
void sqr() {
	double a; double r; char re[100]; 
	printf("请输入要开方的数");
	scanf("%lf", &a);
	r = sqrt(a);
	if (isnan(r)) {
		printf("输入的数据无法开方");
			return ;
	}
	printf(">>>%lf\n", r);
	sprintf(re, "%lf开方为%lf", a, r);
	fileadd(re);
}