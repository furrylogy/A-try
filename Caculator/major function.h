#define major function_h
#pragma once
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int addsub(char*a);
void mypow();//������
int mypow1();//�����㷵��
void gcd();//���������������
void gcd1();//����������߼�����
int gcd2();//�����������
void sqr();//����
void fileadd(char re[100]);//���ļ�ĩβ�����ַ�
void trigonometric1();//���Ǻ�������
void trigonmetric2();//���Ǻ�����
void lcm();//��С������
int integerjudge();//�����жϣ�Ϊ��������1�����Ƿ���0
int recover();//�ָ������ŵ�����
int sizearr1();//����λ����������
int sizearr2();//������λ��
void decimal1();//����ת��
int Takeinteger();//ȡ��������
double TakeDecimal();//ȡС������
void cutime();//ʱ�䲿��ѡ����
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
void line();


typedef struct digit {
	char a[100];//�洢����
	int size;//����λ�����������ţ�
	int b;
} digit;//���ڴ����Ĵ洢
typedef struct data {
	int year;
	int month;
	int day;
}data;//��¼����
typedef struct time {
	int hour;
	int minute;
	int second;
}time;//��¼ʱ��