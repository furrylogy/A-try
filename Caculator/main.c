#define  _CRT_SECURE_NO_WARNINGS
#include"major function.h"
void print() {
	printf("***************************************************************************\n");
	printf("��ѡ�����:\n");
	printf("0.�˳�      1.������      2.����\n");
	printf("3.���������     4.���Ǻ���       5.��С������\n");
	printf("6.����ת��   7.ʱ�����    8.��������ֱ�߽���\n");
	return;
 }

void select(int a) {
	switch (a) {
	case 0:exit(0);
	case 1:mypow(); break;//������
	case 2:sqr(); break;//����
	case 3:gcd(); break;//�������
	case 4:trigonometric1(); break;//���Ǻ���
	case 5:lcm(); break;//��С������
	//case 6:decimal1(); break;//����ת��
	case 7:cutime(); break;
	default:printf("�벻Ҫ������������,����������\n"); scanf("%d", &a);
		select(a); break;
	}
	print();
	scanf("%d", &a);
	select(a);
}

int main() {
	int c;
	print();
	scanf("%d", &c);
	select(c);
	return 0;
}