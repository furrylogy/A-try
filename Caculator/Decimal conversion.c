#define  _CRT_SECURE_NO_WARNINGS
#include"major function.h"
int i = 0;
char zi[] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','Q','V','W','X','Y','Z' };
int arr[100]; char ne[100]; char re[100];

void turn(int x, int n, int* arr, int* i) {
    if (x > 0) {
        arr[*i] = x % n;
        x /= n;
        (*i)++;
        turn(x, n, arr, i);
    }
}

void decimal1() {
    int x, n; // x为原数字，n为进制数  
    printf("请输入两个数，第一个为原数字，第二个为目标进制数\n");
    scanf("%d%d", &x, &n);
    if (n < 2 || n>36) {
        printf("无法转换\n");
        decimal1(); return;
    }
    i = 0; // 重置i的值  
    turn(x, n, arr, &i);
    int a;
    for (a = i - 1; a >= 0; a--) {
        if (arr[a] <= 9) {
         
            ne[i-1-a] = (char)arr[a] + '0';
        }
        else {
          
            ne[i-1-a] = zi[(arr[a] - 10)];
        }
    }
    
    sprintf(re,"%d转换为%d进制为%s\n", x, n, ne);
    printf("%s", re);
    fileadd(re);

}

	