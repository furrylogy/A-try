#define  _CRT_SECURE_NO_WARNINGS
#include"major function.h"
void lcm() {
    int an; double a, b; char re[100];
    printf("������������������\n");
    scanf("%lf%lf", &a, &b);
    if ((!(a - (int)a == 0)) || (!(b - (int)b == 0))) {
        printf("�����޷�����\n");
        return;
    }//�ж������Ƿ����
   (int) an= a * b / gcd2((int)a, (int)b);
   sprintf(re,"lcm(%d,%d)=%d\n",(int) a,(int) b, an);
   printf("%s\n", re);
   fileadd(re);
   return;
}