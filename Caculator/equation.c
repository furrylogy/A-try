#define  _CRT_SECURE_NO_WARNINGS
#include "major function.h"
void equation() {
    double a, b, c, discriminant, root1, root2;

    printf("请输入一元二次方程的系数（按ax^2+ bx+c=0 的顺序输入，以空格分隔）：\n");
    scanf("%lf %lf %lf", &a, &b, &c);

    if (a == 0) {
        printf("这不是一个一元二次方程。\n");
        return;
    }

    discriminant = b * b - 4 * a * c;

    if (discriminant < 0) {
        printf("方程没有实数解。\n");
        return;
    }
    else if (discriminant == 0) {
        root1 = -b / (2 * a);
        printf("方程有一个实数解：x = %.2lf\n", root1);
    }
    else {
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("方程有两个实数解：x1 = %.2lf, x2 = %.2lf\n", root1, root2);
    }
}