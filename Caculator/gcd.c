#define  _CRT_SECURE_NO_WARNINGS
#include"major function.h"
char re[100];
int integerjudge();
void gcd1(int a,int b,int c,int d) {
    
    if (b == 0) {
        sprintf(re, "gcd(%d,%d)=%d\n", c, d, a);
        printf(">>>gcd(%d,%d)=%d\n", c, d, a);
        fileadd(re);
        return ;
    }
    else {
        gcd1(b, a % b,c,d);
    }
}
void gcd() {
    double a, b;
    printf("请输入两个整数数字\n");
    scanf("%lf%lf", &a, &b);
    if (integerjudge(a) || integerjudge(b)) {
        printf("数据无法计算");
            return;
    }//判断数据是否合理
    int c, d; c = a; d = b;//保存原始数据;
    gcd1(a, b,c,d);

}
int gcd2(int a, int b) {
    if (b == 0) {
        return a;
    }
    else {
        gcd2(b, a % b);
    }
}
