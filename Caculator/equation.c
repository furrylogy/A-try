#define  _CRT_SECURE_NO_WARNINGS
#include "major function.h"
void equation() {
    double a, b, c, discriminant, root1, root2;

    printf("������һԪ���η��̵�ϵ������ax^2+ bx+c=0 ��˳�����룬�Կո�ָ�����\n");
    scanf("%lf %lf %lf", &a, &b, &c);

    if (a == 0) {
        printf("�ⲻ��һ��һԪ���η��̡�\n");
        return;
    }

    discriminant = b * b - 4 * a * c;

    if (discriminant < 0) {
        printf("����û��ʵ���⡣\n");
        return;
    }
    else if (discriminant == 0) {
        root1 = -b / (2 * a);
        printf("������һ��ʵ���⣺x = %.2lf\n", root1);
    }
    else {
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("����������ʵ���⣺x1 = %.2lf, x2 = %.2lf\n", root1, root2);
    }
}