#define major function_h
#pragma once
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void mypow();//幂运算
int mypow1();//幂运算返回
void gcd();//最大公因数，初处理
void gcd1();//最大公因数，逻辑处理
int gcd2();//返回最大公因数
void sqr();//开方
void fileadd(char re[100]);//在文件末尾加上字符
void trigonometric1();//三角函数弧度
void trigonmetric2();//三角函数度
void lcm();//最小公倍数
int integerjudge();//整数判断，为整数返回1，不是返回0
int recover();//恢复带符号的数字
int sizearr1();//数字位数，带符号
int sizearr2();//纯数字位数
void decimal1();//进制转换
int Takeinteger();//取整数部分
double TakeDecimal();//取小数部分
void cutime();//时间部分选择函数
int changetime1();
int changetime2(); 
int changetime3();
int changetime4();
int changetime5(); 
int msjudge();
int hrjudge();
int moreyear();
int judgeday();
int comparedata();
int cuday();
void line();//解直线
void equation();//070302  207032


typedef struct digit {
	char a[100];//存储数字
	int size;//数字位数（不含符号）
	int b;
} digit;//对于大数的存储
typedef struct data {
	int year;
	int month;
	int day;
}data;//记录日期
typedef struct time {
	int hour;
	int minute;
	int second;
}time;//记录时间