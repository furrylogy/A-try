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
    printf("������������������\n");
    scanf("%lf%lf", &a, &b);
    if (integerjudge(a) || integerjudge(b)) {
        printf("�����޷�����");
            return;
    }//�ж������Ƿ����
    int c, d; c = a; d = b;//����ԭʼ����;
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
