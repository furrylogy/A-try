#define  _CRT_SECURE_NO_WARNINGS
#include "major function.h"
void sqr() {
	double a; double r; char re[100]; 
	printf("������Ҫ��������");
	scanf("%lf", &a);
	r = sqrt(a);
	if (isnan(r)) {
		printf("����������޷�����");
			return ;
	}
	printf(">>>%lf\n", r);
	sprintf(re, "%d����Ϊ%lf", a, r);
	fileadd(re);
}