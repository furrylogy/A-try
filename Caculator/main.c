#define  _CRT_SECURE_NO_WARNINGS
#include"major function.h"
void print() {
	printf("***************************************************************************\n");
	printf("请选择操作:\n");
	printf("0.退出                1.幂运算         2.开方\n");
	printf("3.最大公因数          4.三角函数       5.最小公倍数\n");
	printf("6.进制转换            7.时间计算       8.计算两条直线交点\n");
	printf("9.计算二元一次方程解  10.大数运算(禁用）      11.四则运算\n");
	printf("12.对数运算           13.阶乘和组合     14.读取记录\n");
	printf("***************************************************************************\n");
	return;
 }

int main() {
	int c;
	print();
	while(1){
		scanf("%d", &c);
			switch (c) {
			case 0:filedelete(); exit(0);
			case 1:mypow(); break;//幂运算
			case 2:sqr(); break;//开方
			case 3:gcd(); break;//最大公因数
			case 4:trigonometric1(); break;//三角函数
			case 5:lcm(); break;//最小公倍数
			case 6:decimal1(); break;//进制转换
			case 7:cutime(); break;//时间计算
			case 8:line(); break;//求两条直线的交点
			case 9:equation(); break;//解一元二次方程
			case 10: maxcaculatorpre(); break;//大数运算
			case 11:Fouroperations(); break;//四则运算
			case 12:logarithm(); break;
			case 13:factorial(); break;
			case 14:fileget(); break;
			default:printf("请不要输入错误的数字,请重新输入\n");continue;
		}
		print();
	}
	return 0;
}