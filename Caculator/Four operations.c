#define  _CRT_SECURE_NO_WARNINGS
#include "major function.h"
void Fouroperations() {
	char arr[1000]; char a[100];//���ڴ�������ַ�
	int n=0;//״̬�룬���ڼ�¼��һ���ǲ�������
	int t=0;//���ڼ�¼a��λ��
	int s=0;//���ڼ�¼�Ƿ��С�.��
	double r;//������ʱ��¼����
	printf("���������ʽ\n");
	scanf(" %s", arr);
	stackn number;
	stacks symbol;
	number.capacity = 100; number.top = -1; number.arr = malloc(100 * sizeof(double));
	symbol.capacity = 100; number.top = -1; number.arr = malloc(100 * sizeof(char));
	for (int i = 0; i < 1000; i++) {
		if(judgesymbol(arr[i])) {
			if (n == 1) {
				switch (s) {
				case 1:r = atof(a); pushn(r, number); n = 0; break;
				case 0: r = atoi(a); pushn(r, number); n = 0; break;
				}
			}
		}//�Զ�λ������
		if (judgesymbol(arr[i])) {
			if (arr[i] == '(') {
				pushs(symbol, '(');
			}
			else {

				next(number,symbol, arr[i]);
			}
		}
			if (isdigit(arr[i])) {
				s = 1;
			}
			a[t] = arr[i]; t++;
			n = 1;
		
	}
}