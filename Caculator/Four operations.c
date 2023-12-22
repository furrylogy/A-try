#define  _CRT_SECURE_NO_WARNINGS
#include "major function.h"
void Fouroperations() {
	char arr[1000]; char a[100];//用于存放数字字符
	int n=0;//状态码，用于记录上一个是不是数字
	int t=0;//用于记录a的位数
	int s=0;//用于记录是否有‘.’
	double r;//用于暂时记录数字
	printf("请输入计算式\n");
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
		}//对多位数处理
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