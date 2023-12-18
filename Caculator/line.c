#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  
#include "major function.h"
void line() {
    double a, b, c, d, e, f;
    double x, y; char re[100];

    printf("请按照格式输入两条直线前的系数  ax+b=cy\n");
    scanf("%lf%lf%lf%lf%lf%lf", &a, &b, &c, &d, &e, &f);

    if ((a == 0 && d == 0) || (c == 0 && e == 0) || (a * e == c * d)) {
        printf("两条直线平行（重合）\n");
        return;
    }

    
    x = (b * e - c * f) / (a * e - c * d);
    y = (a * f - b * d) / (a * e - c * d);

    sprintf(re,"两条直线的交点是：(%lf, %lf)\n", x, y);
    printf("%s", re);
    fileadd(re);
}

