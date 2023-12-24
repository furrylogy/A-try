#define  _CRT_SECURE_NO_WARNINGS
#include"major function.h"

double calculateLogarithm(double base, double number) {
    double result;

    // 检查基数是否有效  
    if (base <= 0 || base == 1) {
        printf("数字不合法\n");
        return;
    }

    // 检查数字是否有效  
    if (number <= 0) {
        printf("数字不合法\n");
        return;
    }

    // 计算对数并打印结果  
    result = log(number) / log(base);
    return result;
}

void logarithm() {
    double base, number, result; char re[100];
    printf("输入底数: ");
    scanf("%lf", &base);

    printf("输入数字 ");
    scanf("%lf", &number);

    result = calculateLogarithm(base, number);
    sprintf(re, "log%lf %lf是%lf\n", base, number, result);
    printf("%s", re);
    fileadd(re);
    return ;
}