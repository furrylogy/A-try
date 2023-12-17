#define  _CRT_SECURE_NO_WARNINGS
void line() {
	double a, b, c, d, e, f;
	printf("请按照格式输入两条直线前的系数  ax+b=cy\n");
	scanf("%lf%lf%lf%lf%lf%lf", &a, &b, &c, &d, &e, & f);
	if ((a == 0 && d == 00) || (c == 0 && f == 0) || (a / c == d / f)) {
		printf("两条直线平行（重合）\n");
		return;
	}

}