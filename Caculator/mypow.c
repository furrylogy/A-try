#define  _CRT_SECURE_NO_WARNINGS
#include"major function.h"
double p; FILE* file; char re[100];
void mypow() {
    double a, b, p;
    char re[100];
    FILE* file;
    printf("请输入底数和指数: ");
    scanf("%lf %lf", &a, &b);  

    p = pow(a, b);
    if (isnan(p)) {
        printf("输入的数据无法计算\n");
        return;
    }

    sprintf(re, "%lf^%lf = %.2f\n",a,b, p); 
    printf(">>> %s", re);

    
    fileadd(re);
    return;
}