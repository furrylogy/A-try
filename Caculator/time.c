#define  _CRT_SECURE_NO_WARNINGS
#include"major function.h"
int arr1[13] = { 0,31,59,90,120,151,181,212,243,273,304,334,365 };
int arr2[13] = { 0,31,60,91,121,152,182,213,244,274,305,335,366 };
int arr3[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
int arr4[13] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };
void betime();
void fdata();//����ѡ����
void ftime();//ʱ��ѡ����
void beftime();
void aftime();
void betdata();
void befdata();
data befdata1();//����
data befdata2();
data befdata3();//��ʼΪ����
data befdata4();
int t();
void cutime () {//ѡ����
	int a;
	printf("�������Ҫ���еĲ�����\n");
	printf("1.�����յļ���    2.24Сʱ�Ƶļ���\n");
	scanf("%d", &a);
	switch (a) {
	case 1:fdata(); break;
	case 2:ftime(); break;
	}
}
	void fdata() {
		int a;
		printf("��ѡ��Ҫ����ķ�ʽ(���������ʽ����2023 12 15)\n");
		printf("1.������������֮�������   2.����������ں��������������   3�����������ǰ��������������\n");
		scanf("%d", &a);
		switch (a) {
		case 1:betdata(); break;
		case 2:befdata(); break;
		case 3:aftdata(); break;
		default:printf("ѡ�������⣬����������\n"); fdata(); break;
		}
	}
	void aftdata() {

	}
	void ftime() {
		int a;
		printf("��ѡ��Ҫ����ķ�ʽ(ʱ�������ʽ��12 45 12  ˳��Ϊʱ����)\n");
		printf("1.��������ʱ��֮��Ĳ�ֵ   2.�������ʱ���ĸ�����������ʱ��   3.�������ʱ��ǰ�ĸ������ӵ�ʱ��\n");
		scanf("%d", &a);
		switch (a) {
		case 1:betime(); break;
		case 2:beftime(); break;
		case 3:aftime(); break;
		default:printf("ѡ�������⣬����������\n"); ftime();break;
		}
	}
	void befdata() {
		char re[100];
		data p; int day; data anw = { 0 }; int day1; 
		printf("������һ������\n");
		scanf("%d%d%d", &p.year, &p.month, &p.day); int day2 = p.day;
		if (!judgeday(p.year, p.month, p.day)) {
			printf("����������\n"); befdata(); return;
		}
		printf("����������\n");
		scanf("%d", &day);//dayΪ��������
		day1 = cuday(p);//day1Ϊ���������Ѿ���ȥ����Ŀ
		if (moreyear(p.year)) {
			if (day1 + day < 366) {
				p.day = day1 + day;
				anw = befdata1(p);
			}
			else {
				p.day = day1 + day;//�����������Ͳ�������֮��
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
			sprintf(re,"%d��%d��%d�պ�%d����%d��%d��%d��\n",p.year,p.month,day2,day, anw.year, anw.month, anw.day); 
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
		data anw = { 0 }; int day1 = 0;/*day1��¼����������ѭ������� */int day2 = 0;//day2���ڼ�¼�����������������
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
		data anw = { 0 }; int day1 = 0;/*day1��¼����������ѭ������� */int day2 = 0;//day2���ڼ�¼�����������������
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
		printf("��������������\n");
		scanf("%d%d%d", &p.year, &p.month, &p.day);
		if (!judgeday(p.year, p.month, p.day)) {
			printf("����������\n"); betdata(); return;
		}
		scanf("%d%d%d", &b.year, &b.month, &b.day);
		if (!judgeday(p.year, p.month, p.day)) {
			printf("����������\n"); betdata(); return;
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
			
		}sprintf(re, "%d��%d��%d�պ�%d��%d��%d��֮��Ĳ�Ϊ%d��\n", p.year, p.month, p.day, b.year, b.month, b.day, day);
		printf("%s", re);
		fileadd(re); return;
	}
	int t(data p, data b) {//���������Ĳ��
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
		printf("����������\n");
		time p; int r, t, y, u, i; char re[100];//sc,r,t,y,u,i�ֱ�Ϊ��ֵ��������ֵ����������ֵʱ������
		scanf("%d%d%d", &p.hour, &p.minute, &p.second);
		if (!(hrjudge(p.hour) &&msjudge(p.minute) && msjudge(p.second))) {
			printf("���ݲ�������ʵ������������\n");
			betime();
		}
		time b;
		scanf("%d%d%d", &b.hour, &b.minute, &b.second);
		if (!(hrjudge(b.hour) && msjudge(b.minute) && msjudge(b.second))) {
			printf("���ݲ�������ʵ,��������������ʱ��\n");
			betime();
		}
		sc = 3600 * p.hour + 60 * p.hour + p.second - 3600 * b.hour - 60 * b.minute - b.second;
		if (sc < 0) {
			sc = -sc;
		}
		r = changetime1(sc); t = changetime2(sc); y = changetime3(sc); u = changetime4(sc); i = changetime5(sc);
		printf("��ֵΪ%d�룬��Ϊ%d��%d�룬��%dСʱ%d��%d��\n", sc, r, t, y, u, i); 
		sprintf(re, "%dʱ%d��%d����%dʱ%d��%d��Ĳ�Ϊ%d�룬��Ϊ%d��%d�룬��%dСʱ%d��%d��\n", p.hour, p.minute, p.second, b.hour, b.minute, b.second, sc, r, t, y, u, i);
		printf("%s", re);
		fileadd(re);
		return;
	}
	void beftime() {
		char re[100];
		time p; int min,min2,min1,ho1,day; printf("��������ʱ�䣬�����������\n");
		scanf("%d%d%d", &p.hour, &p.minute, &p.second);
		if (!(hrjudge(p.hour) && msjudge(p.minute) && msjudge(p.second))) {
			printf("���ݲ�������ʵ������������\n");
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
			printf("%dʱ%d��%d���%d����%dʱ%d��%d��,���У��Ѿ�����%d��\n", p.hour, p.minute, p.second, min, ho1, min1, p.second, day); 
			sprintf(re, "%dʱ%d��%d���%d����%dʱ%d��%d��,���У��Ѿ�����%d��\n", p.hour, p.minute, p.second, min, ho1, min1, p.second, day); 
			fileadd(re); return;
		}
		else {
			printf("%dʱ%d��%d���%d����%dʱ%d��%d��\n", p.hour, p.minute, p.second, min, ho1, min1, p.second);
			sprintf(re, "%dʱ%d��%d���%d����%dʱ%d��%d��\n", p.hour, p.minute, p.second, min, ho1, min1, p.second);
			fileadd(re);
			return;
		}
	}
	void aftime() {
		time p; int min,min2,min3,min1,ho1,ho2,day; //minΪ��ʼ���ݣ�min1Ϊ�����ݣ�min2Ϊ����ת�����ݣ�min3Ϊ�������ݣ�dayΪ������������holΪ��Сʱ��ho2Ϊ����Сʱ
		printf("��������ʱ�䣬�����������\n");
		scanf("%d%d%d", &p.hour, &p.minute, &p.second);
		if (!(hrjudge(p.hour) && msjudge(p.minute) && msjudge(p.second))) {
			printf("���ݲ�������ʵ������������\n");
			beftime(); return;
		}
		scanf("%d", &min);
		day = min / 1440;
		min2 = min % 1440;//�ų��������������
		if (min2 > (p.hour*60 + p.minute)) {
			min2 = min - p.hour * 60 - p.minute;
			min2 = min2 % 60;
			min1 = 60 - min2;
			ho2 = min2 / 60;
			ho1 = 24 - ho2;
			printf("%dʱ%d��%d���ǰ%d������%dʱ%d��%d�룬�Ѿ���%d��\n", p.hour, p.minute, p.second, min, ho1, min1, p.second,day);
		}//�ѵ�ǰһ�����
		else {
			min2 =  p.hour * 60 + p.minute-min2;
			min1 = min2 % 60;
			ho1 = min2 / 60;
			printf("%dʱ%d��%d���ǰ%d������%dʱ%d��%d�룬�Ѿ���%d��\n", p.hour, p.minute, p.second, min, ho1, min1, p.second, day);
		}
	}
	