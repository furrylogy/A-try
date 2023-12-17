#define  _CRT_SECURE_NO_WARNINGS
#include"major function.h"
void print() {
	printf("***************************************************************************\n");
	printf("请选择操作:\n");
	printf("0.退出      1.幂运算      2.开方\n");
	printf("3.求最大公因数     4.三角函数       5.最小公倍数\n");
	printf("6.进制转换   7.时间计算    8.计算两条直线交点\n");
	return;
 }

void select(int a) {
	switch (a) {
	case 0:exit(0);
	case 1:mypow(); break;//幂运算
	case 2:sqr(); break;//开方
	case 3:gcd(); break;//最大公因数
	case 4:trigonometric1(); break;//三角函数
	case 5:lcm(); break;//最小公倍数
	//case 6:decimal1(); break;//进制转换
	case 7:cutime(); break;
	default:printf("请不要输入错误的数字,请重新输入\n"); scanf("%d", &a);
		select(a); break;
	}
	print();
	scanf("%d", &a);
	select(a);
}

int main() {
	int c;
	print();
	scanf("%d", &c);
	select(c);
	return 0;
}