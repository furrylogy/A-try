#define  _CRT_SECURE_NO_WARNINGS
#include "major function.h"
void Fouroperations() {
	char arr[1000]; char a[100];//用于存放数字字符
	int n=0;//状态码，用于记录上一个是不是数字
	int t=0;//用于记录a的位数
	int s=0;//用于记录是否有‘.’
	double r;//用于暂时记录数字
	char re[1000];
	printf("请输入计算式\n");
	scanf(" %s", arr);
	stackn number;
	stacks symbol;
	number.capacity = 100; number.top = -1; number.arr = malloc(100 * sizeof(double));
	symbol.capacity = 100; symbol.top = -1; symbol.arr = malloc(100 * sizeof(char));
	for (int i = 0; i < 1000; i++) {
		if (arr[i] ==  '\0') {
			if (n == 1) {
				switch (s) {
				case 1:r = atof(a); pushn(&number, r); n = 0; t = 0; memset(a, 0, sizeof(a));   break;
				case 0: r = atoi(a); pushn(&number, r); n = 0; t = 0; memset(a, 0, sizeof(a));   break;
				}
			}
			next(&number, &symbol, arr[i]);
			break;
		}
		if(judgesymbol(arr[i])) {
			if (n == 1) {
				switch (s) {
				case 1:r = atof(a);pushn(&number, r); n = 0; t = 0;  memset(a, 0, sizeof(a)); break;
				case 0: r = atoi(a);pushn(&number, r); n = 0; t = 0; memset(a, 0, sizeof(a)); break;
				}
			}
		}//对多位数处理
		if (judgesymbol(arr[i])) {
			if (arr[i] == '(') {
				pushs(&symbol, arr[i]);
			}
			else {
				if (symbol.top == -1) {
					pushs(&symbol, arr[i]);
				}
				else {
					next(&number, &symbol, arr[i]);
				}
			}
		}
		if (isdigit(arr[i]) || arr[i] == '.') {
			if (arr[i] == '.') {
				s = 1;
			}
			a[t] = arr[i]; t++;
			n = 1;
		}
		
	}
	do{
		switch (symbol.arr[symbol.top]) {
		case '+': pushn(&number, (popn(&number) + popn(&number))); pops(&symbol);  break;
		case '-': pushn(&number, (popn(&number) + popn(&number))); pops(&symbol);  break;
		case '*':pushn(&number, (popn(&number) * popn(&number))); pops(&symbol);  break;
		case '/':pushn(&number, 1 / (popn(&number) / popn(&number))); pops(&symbol);  break;
		case'\0':pops(&symbol); break;
		}

	}while (!(symbol.top == -1));
	sprintf(re,"%s的结果是%lf\n",arr,(double)number.arr[0]);
	printf("%s", re);
	fileadd(re);
}

