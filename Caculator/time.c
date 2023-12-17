#define  _CRT_SECURE_NO_WARNINGS
#include"major function.h"
int arr1[13] = { 0,31,59,90,120,151,181,212,243,273,304,334,365 };
int arr2[13] = { 0,31,60,91,121,152,182,213,244,274,305,335,366 };
int arr3[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
int arr4[13] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };
void betime();
void fdata();//日期选择函数
void ftime();//时间选择函数
void beftime();
void aftime();
void betdata();
void befdata();
data befdata1();//闰年
data befdata2();
data befdata3();//初始为闰年
data befdata4();
int t();
void cutime () {//选择函数
	int a;
	printf("请决定你要进行的操作：\n");
	printf("1.年月日的计算    2.24小时制的计算\n");
	scanf("%d", &a);
	switch (a) {
	case 1:fdata(); break;
	case 2:ftime(); break;
	}
}
	void fdata() {
		int a;
		printf("请选择要计算的方式(日期输入格式例：2023 12 15)\n");
		printf("1.计算两个日期之间的天数   2.计算给定日期后给定天数的日期   3计算给定日期前给定天数的日期\n");
		scanf("%d", &a);
		switch (a) {
		case 1:betdata(); break;
		case 2:befdata(); break;
		case 3:aftdata(); break;
		default:printf("选项有问题，请重新输入\n"); fdata(); break;
		}
	}
	void aftdata() {

	}
	void ftime() {
		int a;
		printf("请选择要计算的方式(时间输入格式例12 45 12  顺序为时分秒)\n");
		printf("1.计算两个时间之间的差值   2.计算给定时间后的给定分钟数的时间   3.计算给定时间前的给定分钟的时间\n");
		scanf("%d", &a);
		switch (a) {
		case 1:betime(); break;
		case 2:beftime(); break;
		case 3:aftime(); break;
		default:printf("选项有问题，请重新输入\n"); ftime();break;
		}
	}
	void befdata() {
		char re[100];
		data p; int day; data anw = { 0 }; int day1; 
		printf("请输入一个日期\n");
		scanf("%d%d%d", &p.year, &p.month, &p.day); int day2 = p.day;
		if (!judgeday(p.year, p.month, p.day)) {
			printf("数据有问题\n"); befdata(); return;
		}
		printf("请输入天数\n");
		scanf("%d", &day);//day为经过天数
		day1 = cuday(p);//day1为输入日期已经过去的数目
		if (moreyear(p.year)) {
			if (day1 + day < 366) {
				p.day = day1 + day;
				anw = befdata1(p);
			}
			else {
				p.day = day1 + day;//经过的天数和查找日期之和
				anw = befdata3(p, day1);
			}
		}
		else {
				if (day1 + day < 365) {
					p.day = day1 + day;
					anw = befdata2(p);
				}
				else {
					p.day = day1 + day;
					anw = befdata4(p,day1);
				}

			}
			sprintf(re,"%d年%d月%d日后%d天是%d年%d月%d日\n",p.year,p.month,day2,day, anw.year, anw.month, anw.day); 
			printf("%s", re);
			fileadd(re);
		}
	data befdata1(data p) {
		data anw; int day = p.day; int day1=0; int i = 0;
		anw.year = p.year;
		do {
			i++;
			day1 =arr2[i];
		} while (day1 < day);
		
		anw.month = i;
		anw.day = day - arr2[i-1];
		return anw;
	}
	data befdata2(data p) {
		data anw; int day = p.day; int day1 = 0; int i = 0;
		anw.year = p.year;
		do {
			i++;
			day1 = arr1[i];
		} while (day1 < day);

		anw.month = i;
		anw.day = day - arr1[i - 1];
		return anw;
	}
	data befdata3(data p,int dayago) {
		data anw = { 0 }; int day1 = 0;/*day1记录天数，用于循环找年份 */int day2 = 0;//day2用于记录经过的完整年份天数
		int year1 = p.year;
		do {
			year1++;
			if (moreyear(year1)) {
				day2 = day2 + 366;
				day1 = day1 + 366;
			}
			else {
				day2 = day2 + 365;
				day1 = day1 + 365;
			}
		} while (day1 <366-( p.day - dayago));
		if (moreyear(year1)) {
			day2 = day2 - 366;
		}
		else {
			day2 = day2 - 365;
		}
		anw.year = year1;
		if (moreyear(anw.year)) {
			anw.day = p.day - day2 - 366;
			anw = befdata1(anw);
		}
		else {
			anw.day = p.day - day2 - 366;
			anw = befdata2(anw);
		}return anw;
	}
	data befdata4(data p, int dayago) {
		data anw = { 0 }; int day1 = 0;/*day1记录天数，用于循环找年份 */int day2 = 0;//day2用于记录经过的完整年份天数
		int year1 = p.year;
		do {
			year1++;
			if (moreyear(year1)) {
				day2 = day2 + 366;
				day1 = day1 + 366;
			}
			else {
				day2 = day2 + 365;
				day1 = day1 + 365;
			}
		} while (day1 < 365 - (p.day - dayago));
		if (moreyear(year1)) {
			day2 = day2 - 366;
		}
		else {
			day2 = day2 - 365;
		}
		anw.year = year1;
		if (moreyear(anw.year)) {
			anw.day = p.day - day2 - 365;
			anw = befdata1(anw);
		}
		else {
			anw.day = p.day - day2 - 365;
			anw = befdata2(anw);
		}return anw;
	}
	void betdata() {
		data p;
		data b; int day = 0; char re[100];
		printf("请输入两个日期\n");
		scanf("%d%d%d", &p.year, &p.month, &p.day);
		if (!judgeday(p.year, p.month, p.day)) {
			printf("数据有问题\n"); betdata(); return;
		}
		scanf("%d%d%d", &b.year, &b.month, &b.day);
		if (!judgeday(p.year, p.month, p.day)) {
			printf("数据有问题\n"); betdata(); return;
		}
		
		if (comparedata(p, b)) {
			if (p.year == b.year) {
				day = cuday(p) - cuday(b);
			}
			else {
				day = t(p, b);
			}
		}else{
			if (p.year == b.year) {
				day = cuday(b) - cuday(p);
			}
			else {
				day = t(b, p);
			}
			
		}sprintf(re, "%d年%d月%d日和%d年%d月%d日之间的差为%d天\n", p.year, p.month, p.day, b.year, b.month, b.day, day);
		printf("%s", re);
		fileadd(re); return;
	}
	int t(data p, data b) {//计算天数的差距
		int day=0;
		for (int i = p.year - 1; i > b.year; i--) {
			if (moreyear(i)) {
				day = day + 366;
			}
			else {
				day = day + 365;
			}
		}
		day = day + cuday(p);
		if (moreyear(b.year)) {
			day = day + 366 - cuday(b) +1;
		}
		else {
			day = day + 365 - cuday(b)+1;
		}return day;
	}
	void betime() {
		int sc;
		printf("请输入数据\n");
		time p; int r, t, y, u, i; char re[100];//sc,r,t,y,u,i分别为差值秒数，差值分秒数，差值时分秒数
		scanf("%d%d%d", &p.hour, &p.minute, &p.second);
		if (!(hrjudge(p.hour) &&msjudge(p.minute) && msjudge(p.second))) {
			printf("数据不符合现实，请重新输入\n");
			betime();
		}
		time b;
		scanf("%d%d%d", &b.hour, &b.minute, &b.second);
		if (!(hrjudge(b.hour) && msjudge(b.minute) && msjudge(b.second))) {
			printf("数据不符合现实,请重新输入两个时间\n");
			betime();
		}
		sc = 3600 * p.hour + 60 * p.hour + p.second - 3600 * b.hour - 60 * b.minute - b.second;
		if (sc < 0) {
			sc = -sc;
		}
		r = changetime1(sc); t = changetime2(sc); y = changetime3(sc); u = changetime4(sc); i = changetime5(sc);
		printf("差值为%d秒，即为%d分%d秒，或%d小时%d分%d秒\n", sc, r, t, y, u, i); 
		sprintf(re, "%d时%d分%d秒与%d时%d分%d秒的差为%d秒，即为%d分%d秒，或%d小时%d分%d秒\n", p.hour, p.minute, p.second, b.hour, b.minute, b.second, sc, r, t, y, u, i);
		printf("%s", re);
		fileadd(re);
		return;
	}
	void beftime() {
		char re[100];
		time p; int min,min2,min1,ho1,day; printf("请先输入时间，再输入分钟数\n");
		scanf("%d%d%d", &p.hour, &p.minute, &p.second);
		if (!(hrjudge(p.hour) && msjudge(p.minute) && msjudge(p.second))) {
			printf("数据不符合现实，请重新输入\n");
			beftime(); return;
		}
		scanf("%d", &min);
		min2 = min %1440 ;
		day = min / 1440;
		min1 = (min + p.minute) % 60;
		ho1 = p.hour + ((int)(min2 + p.minute) / 60);
		if (ho1 > 24) {
			ho1 = ho1 - 24;
		}if (day > 0) {
			printf("%d时%d分%d秒后%d分是%d时%d分%d秒,其中，已经经过%d天\n", p.hour, p.minute, p.second, min, ho1, min1, p.second, day); 
			sprintf(re, "%d时%d分%d秒后%d分是%d时%d分%d秒,其中，已经经过%d天\n", p.hour, p.minute, p.second, min, ho1, min1, p.second, day); 
			fileadd(re); return;
		}
		else {
			printf("%d时%d分%d秒后%d分是%d时%d分%d秒\n", p.hour, p.minute, p.second, min, ho1, min1, p.second);
			sprintf(re, "%d时%d分%d秒后%d分是%d时%d分%d秒\n", p.hour, p.minute, p.second, min, ho1, min1, p.second);
			fileadd(re);
			return;
		}
	}
	void aftime() {
		time p; int min,min2,min3,min1,ho1,ho2,day; //min为起始数据，min1为答案数据，min2为天数转换数据，min3为计算数据，day为经过的天数，hol为答案小时，ho2为计算小时
		printf("请先输入时间，再输入分钟数\n");
		scanf("%d%d%d", &p.hour, &p.minute, &p.second);
		if (!(hrjudge(p.hour) && msjudge(p.minute) && msjudge(p.second))) {
			printf("数据不符合现实，请重新输入\n");
			beftime(); return;
		}
		scanf("%d", &min);
		day = min / 1440;
		min2 = min % 1440;//排除分钟数过大跨天
		if (min2 > (p.hour*60 + p.minute)) {
			min2 = min - p.hour * 60 - p.minute;
			min2 = min2 % 60;
			min1 = 60 - min2;
			ho2 = min2 / 60;
			ho1 = 24 - ho2;
			printf("%d时%d分%d秒的前%d分钟是%d时%d分%d秒，已经过%d天\n", p.hour, p.minute, p.second, min, ho1, min1, p.second,day);
		}//已到前一天或几天
		else {
			min2 =  p.hour * 60 + p.minute-min2;
			min1 = min2 % 60;
			ho1 = min2 / 60;
			printf("%d时%d分%d秒的前%d分钟是%d时%d分%d秒，已经过%d天\n", p.hour, p.minute, p.second, min, ho1, min1, p.second, day);
		}
	}
	