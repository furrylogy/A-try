#define  _CRT_SECURE_NO_WARNINGS
#include"major function.h"
double p; FILE* file; char re[100];
void mypow() {
    double a, b, p;
    char re[100];
    FILE* file;
    printf("�����������ָ��: ");
    scanf("%lf %lf", &a, &b);  

    p = pow(a, b);
    if (isnan(p)) {
        printf("����������޷�����\n");
        return;
    }

    sprintf(re, "%lf^%lf = %.2f\n",a,b, p); 
    printf(">>> %s", re);

    
    fileadd(re);
    return;
}