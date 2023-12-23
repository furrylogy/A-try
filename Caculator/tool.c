#define  _CRT_SECURE_NO_WARNINGS
#include"major function.h"
int integerjudge(double a) {
    if (!(a - (int)a == 0))
        return 1;
    else
        return 0;
}
int sizearr1(char* arr) {
    int i = 0;
    while (arr[i] != '\0') {
        i++;
    }
    return i;
}
int arrsize2(char* arr) {
    int i = 0;
    if (arr[0] == '-') {
        while (arr[i] != '\0') {
            i++;
        }
        return i-1;
    }
    else {
        while (arr[i] != '\0') {
            i++;
        }
        return i;
    }
}
int recover(char*arr,int size) {
    int an=0; int t = 0;
    if (arr[0] == '-') {
        for (int i = size; i >= 1; i--) {
            an = arr[i] * pow(10, t) + an; t++;
        }
        return -an;
    }
    else {
        for (int i = size; i >= 0; i--) {
            an = arr[i] * pow(10, t) + an; t++;
        }
        return an;
    }
}
int Takeinteger(double a) {
    return (int)a;
}
double TakeDecimal(double a) {
    return (a - (int)a);
}
int hrjudge(int a) {
    if (a <= 24 && a >= 0) {
        return 1;
    }
    return 0;
}//确保小时数正确
int msjudge(int a) {
    if (a <= 60 && a >= 0) {
        return 1;
    }
    return 0;
}//确保分钟数和秒数正确
int changetime1(int a) {
    a = a / 60;
    return a;
}//计算分钟数，输入的a为秒数
int changetime2(int a) {
    a = a % 60;
    return a;
}//计算剩余的秒数，输入的a为秒数
int changetime3(int a) {
    a = a / 60;
    a = a / 60;
    return a;
}//计算小时数，输入的a为秒数
int changetime4(int a) {
    a = a / 60;
    a = a % 60;
    return a;
}//计算剩余分钟数，输入的为秒数
int changetime5(int a) {
    a = a % 60;
    return a;
}//计算剩余秒数,输入的为秒数
int moreyear(int x) {
    if (x % 400 == 0)
    {
        return 1;
    }
    else
    {
        if (!(x % 100 == 0) && (x % 4 == 0))
            return 1;
        else
            return 0;
    }
}//判断是否为闰年
int monthjudge(int x) {
    if (x <= 12 && x >= 1) {
        return 1;
    }
    else {
        return 0;
    }
}
int judgeday(int year,int x, int y) {
    switch (x) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:if ((y <= 31) && (y > 0))return 1; else return 0; break;
    case 4:
    case 6:
    case 9:
    case 11:if ((y <= 30) && (y > 0))return 1; else return 0; break;
    case 2:if (moreyear(year)) { if ((y <= 29) && (y > 0)) return 1; else return 0; }
          else {
        if ((y <= 28) && (y > 0)) { return 1; }
        else { return 0; }
    }break;
    default:return 0;
    }
}//判断日期是否正确
int comparedata(data a, data b) {
    if (a.year != b.year) {
        return a.year > b.year ? 1 : 0;
    }
    if (a.month != b.month) {
        return a.month > b.month ? 1 : 0;
    }
    return a.day > b.day ? 1 : 0;
}
//判断a日期是否大于b日期，大于返回1，小于等于返回0
int cuday(data a) {//给出已经过去多少天
    int day;
    int arr1[13] = { 0,31,59,90,120,151,181,212,243,273,304,334,365 };
    int arr2[13] = {0,31,60,91,121,152,182,213,244,274,305,335,366 };//闰年
    day = a.day;
    if (moreyear(a.year)) {
        day = day + arr2[a.month - 1];
    }
    else {
        day = day + arr1[a.month - 1];
    }return day;
}
int isemptys(stacks* a) {
    if (a->top == -1)
        return 1;
    else
        return 0;// 如果栈顶指针为-1，则栈为空  
}
int isemptyn(stackn* a) {
    if (a->top == -1)
        return 1;
    else
        return 0;// 如果栈顶指针为-1，则栈为空  
}
int judgesymbol(char a) {//判断是否为操作符
    if (a == '+' || a == '-' || a == '/' || a == '*'||a=='('||a==')') {
        return 1;
    }
    else 
    {   return 0;
    }
}
void pushs(stacks* stack, char item) {
    if (isFulls(stack)) {  // 如果栈满了，则进行扩容操作  
        stack->capacity *= 2;  // 容量翻倍  
        stack->arr = (char*)realloc(stack->arr, stack->capacity * sizeof(char));  // 重新分配内存空间  
    }
    stack->top++;
    stack->arr[stack->top] = item;// 将元素添加到栈顶，并更新栈顶指针  
}
void pushn(stackn* stack, double item) {
    if (isFulln(stack)) {  // 如果栈满了，则进行扩容操作  
        stack->capacity *= 2;  // 容量翻倍  
        stack->arr = (double*)realloc(stack->arr, stack->capacity * sizeof(double));  // 重新分配内存空间  
    }
    stack->top++;
    stack->arr[stack->top] = item; // 将元素添加到栈顶，并更新栈顶指针  
}
int isFulls(stacks* stack) {
    if (stack->top == stack->capacity - 1)
        return 1;
    else return 0;// 如果栈顶指针等于容量减1，则栈满  
}
int isFulln(stackn* stack) {
    if (stack->top == stack->capacity - 1)
        return 1; else return 0; // 如果栈顶指针等于容量减1，则栈满  
}
double popn(stackn* s) {
    if (isemptyn(s)) {
        printf("Error: stack is empty\n");
        return -1;
    }
    return s->arr[(s->top)--];
}
double pops(stacks* s) {
    if (isemptyn(s)) {
        printf("Error: stack is empty\n");
        return -1;
    }
    return s->arr[(s->top)--];
}
int compare(char a) {
    if (a == '+'||a=='-')
        return 1;
    if (a == '*'||a=='/')
        return 2;
    if (a == '\0') 
        return 0;
    if (a == '(')
        return 0;
    
}
//int needcu(stacks s, char c) {
//    if ( s.arr[s.top]== ('+'||'-')&&c== ('+' || '-'||')'||'*'||'/')) {
//        return 1;
//    }
//    else {
//        return 0;
//    }
//    if (s.arr[s.top] == ('*' || '/') && c == ('*' || '/' || ')')) {
//        return 1;
//    }
//    else {
//        return 0;
//    }
//    if (s.arr[s.top] == '(') {
//        return 0;
//    }
//}
void next(stackn *n,stacks* s, char c) {
    if (c == ')') {
        
        do {
            switch (s->arr[s->top]) {
            case '+':pushn(n, (popn(n) + popn(n))); pops(s);  break;
            case '-':pushn(n, -(popn(n) - popn(n))); pops(s);  break;
            case '*':pushn(n, (popn(n) * popn(n))); pops(s); break;
            case '/':pushn(n, 1/(popn(n) / popn(n))); pops(s);  break;
            }
        } while (!s->arr[s->top] == '(');
        pops(s); return;
    }
    
if (compare(s->arr[s->top]) >= compare(c)) {
    switch (s->arr[s->top]) {
    case '+':pushn(n, (popn(n) + popn(n))); pops(s); pushs(s, c);  break;
    case '-':pushn(n, -(popn(n) - popn(n))); pops(s); pushs(s, c); break;
    case '*':pushn(n, (popn(n) * popn(n))); pops(s); pushs(s, c); break;
    case '/':pushn(n, 1 / (popn(n) / popn(n))); pops(s); pushs(s, c); break;
    }
}
else
{
    pushs(s, c);
}
    
}