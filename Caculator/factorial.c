#define  _CRT_SECURE_NO_WARNINGS
#include"major function.h"
void factorial0();
void Combination_Number_Formula();
void permutation();
void Combination_Number_Formula();
void factorial() {
	int a;
	printf("��ѡ��Ҫ����ķ�ʽ\n");
	printf("1.�׳�2.�����3.������\n");
	scanf("%d", &a);
	switch (a) {
	case 1:factorial0(); break;
	case 2:Combination_Number_Formula(); break;
	case 3:permutation(); break;
	}
}
void factorial0() {
	printf("����������\n"); 
	int a; unsigned long long n = 1; char an[1000]; sprintf(an, "%d", 1); char num1[100]; char num2[1000]; char re[1000];
	scanf("%d", &a);
	if (a < 0) {
		printf("���ֲ��Ϸ�\n");
		factorial0(); return;
	}
	if (a < 12) {
		for (int i = 1; i <= a; i++) {
			n *= i;
		}
		sprintf(re, "%d�Ľ׳���%lld\n",a, n);
		printf("%s", re);
		fileadd(re);
	}
	if (a >= 12) {
		for (int i = 1; i <= a; i++) {
			sprintf(num1, "%d", i);   strcpy(num2, an);
			bigNumberMultiply(num1, num2, an);
		}sprintf(re,"%d�Ľ׳���%s\n", a,an);
		printf("%s", re);
		fileadd(re);
	}
}
void Combination_Number_Formula() {
	printf("�������������֣�ǰ������ϣ����������\n");
	int a; int b; unsigned long long an = 1; unsigned long long an1 = 1; unsigned long long an2 = 1;
	char re[1000];
	scanf("%d%d", &a, &b);
	if (a < 0 || b < 0 || a>b) {
		printf("���벻�Ϸ�\n");
		Combination_Number_Formula();
	}
	for (int i = b; i > (b - a); i--) {
		an1 = i * an1;
	}
	for (int i = 1; i <= a; i++) {
		an2 *= i;
	}
	an = (an1 / an2);
	sprintf(re,"C%d %dΪ%lld",a,b, an);
	printf("%s", re);
	fileadd(re);
}
void permutation() {
	printf("�������������֣�ǰ������ϣ����������\n");
	int a; int b; unsigned long long an = 1; char re[1000];
	scanf("%d", &a); scanf("%d", &b);
	if (a < 0 || b < 0||a>b) {
		printf("���벻�Ϸ�\n");
		permutation();
	}
	for (int i = b; i > (b - a); i--) {
		an = i * an;
	}
	sprintf(re,"A%d %dΪ%lld\n", an);
	printf("%s", re);
	fileadd(re);
}