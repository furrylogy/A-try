#define  _CRT_SECURE_NO_WARNINGS
#include"major function.h"

double calculateLogarithm(double base, double number) {
    double result;

    // �������Ƿ���Ч  
    if (base <= 0 || base == 1) {
        printf("���ֲ��Ϸ�\n");
        return;
    }

    // ��������Ƿ���Ч  
    if (number <= 0) {
        printf("���ֲ��Ϸ�\n");
        return;
    }

    // �����������ӡ���  
    result = log(number) / log(base);
    return result;
}

void logarithm() {
    double base, number, result; char re[100];
    printf("�������: ");
    scanf("%lf", &base);

    printf("�������� ");
    scanf("%lf", &number);

    result = calculateLogarithm(base, number);
    sprintf(re, "log%lf %lf��%lf\n", base, number, result);
    printf("%s", re);
    fileadd(re);
    return ;
}