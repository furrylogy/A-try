#define  _CRT_SECURE_NO_WARNINGS
#include"major function.h"
void bigNumberAdd1();
void bigNumberSubtract1();
void bigNumberMultiply1();
void maxcaculatorpre() {
    int a;
    printf("请选择你要计算的方式(注意，这里只考虑输入的数字都是整数且为整数)\n");
    printf("1.加法2.减法3.乘法4.除法\n");
    scanf("%d", &a);
    switch (a) {
    case 1:bigNumberAdd1(); break;
    case 2:bigNumberSubtract1(); break;
    case 3: bigNumberMultiply1(); break;
    case 4:
    }
}
void reverse(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

// 大数加法  
void bigNumberAdd(char* num1, char* num2, char* result) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);

    // 保证num1是较长的数或两者长度相等  
    if (len1 < len2) {
        char* temp = num1;
        num1 = num2;
        num2 = temp;
        int len = len1;
        len1 = len2;
        len2 = len;
    }

    // 反转两个字符串，方便从低位开始加  
    reverse(num1);
    reverse(num2);

    int carry = 0; // 进位  
    for (int i = 0; i < len2; i++) {
        int sum = num1[i] - '0' + num2[i] - '0' + carry;
        result[i] = sum % 10 + '0'; // 个位数  
        carry = sum / 10; // 进位  
    }
    for (int i = len2; i < len1; i++) {
        int sum = num1[i] - '0' + carry;
        result[i] = sum % 10 + '0'; // 个位数  
        carry = sum / 10; // 进位  
    }
    if (carry > 0) { // 如果最后还有进位，加到结果字符串的最后  
        result[len1] = carry + '0';
        len1++;
    }
    result[len1] = '\0'; // 字符串结束标志  
    reverse(result); // 翻转回来得到最终结果  
}

void bigNumberAdd1() {
    char re[1000];
    char num1[100];
    char num2[100];
    char result[101]; // 结果可能多一位（进位）  
    printf("请输入第一个大数: ");
    scanf("%s", num1);
    printf("请输入第二个大数: ");
    scanf("%s", num2);
    bigNumberAdd(num1, num2, result);
    sprintf(re,"两数之和为: %s\n", result);
    printf("%s", re);
    fileadd(re);
    return ;
}

// 大数减法  
void bigNumSubtract(char* num1, char* num2, char* result) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int diff = len1 - len2;

    // 保证num1是较短的字符串  
    if (diff < 0) {
        char* temp = num1;
        num1 = num2;
        num2 = temp;
        diff = -diff;
    }

    // 处理前导零  
    int start = 0;
    while (start < diff && num1[start] == '0') start++;
    if (start == diff) start--;

    // 对齐两个数字并相减  
    int borrow = 0;  // 借位  
    int i = start;
    while (i < len1) {
        int digit1 = num1[i] - '0';
        int digit2 = i < len2 ? num2[i - diff] - '0' : 0;
        int sub = digit1 - digit2 - borrow;
        borrow = sub < 0 ? 1 : 0;  // 需要借位为1，否则为0  
        sub = (sub + 10) % 10;  // 处理借位后的结果  
        result[i - start] = sub + '0';
        i++;
    }
    result[i - start] = '\0';  // 添加字符串结束标志  

    // 处理结果为负数的情况  
    if (borrow) {  // 如果最后还有借位，说明结果为负数  
        result[0] = '-';  // 添加负号  
        memmove(result + 1, result, strlen(result));  // 将原结果后移一位  
    }
}

void bigNumberSubtract1(){
    char num1[100]; char re[1000];
    char num2[100];
    char result[101]; // 结果可能最多比最长的输入多一位（负号），所以+1是需要的。  
    printf("请输入被减数: ");
    scanf("%s", num1);
    printf("请输入减数: ");
    scanf("%s", num2);
    bigNumSubtract(num1, num2, result);
    sprintf(re,"两数之差为: %s\n", result);
    printf("%s", re);
    fileadd(re);
    return ;
}

// 大数乘法  
void bigNumberMultiply(char* num1, char* num2, char* result) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);

    // 初始化结果数组为全'0'  
    memset(result, '0', len1 + len2 + 1); // 分配足够的空间以容纳结果和进位  
    result[len1 + len2] = '\0'; // 设置字符串结束标志  

    // 反转两个字符串，方便从低位开始乘  
    reverse(num1);
    reverse(num2);

    int carry = 0; // 进位  
    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            int product = (num1[i] - '0') * (num2[j] - '0') + (result[i + j] - '0') + carry; // 当前位的乘积加上之前的进位和之前的结果  
            result[i + j] = product % 10 + '0'; // 当前位的值  
            carry = product / 10; // 进位  
        }
    }
    if (carry > 0) { // 处理最高位的进位  
        result[len1 + len2 - 1] += carry; // 加上进位值，注意这里索引是len1 + len2 - 1而不是i + len2  
        // 这里不需要再清除进位标志，因为已经处理完了所有位的乘积  
    }
    reverse(result); // 翻转回来得到最终结果，注意这里可能最前面有多余的'0'需要处理掉  

    // 去除结果字符串开头的'0'（如果有的话）  
    int index = 0;
    while (result[index] == '0' && index < len1 + len2 - 1) { // 注意这里是len1 + len2 - 1，因为最后一位是'\0'  
        index++;
    }
    if (index > 0) { // 如果有多余的'0'，则移动字符串，并更新长度  
        memmove(result, result + index, len1 + len2 - index + 1); // +1 是为了包含字符串结束符'\0'  
    }
}

void bigNumberMultiply1() {
    char num1[100];
    char num2[100];
    char result[200]; // 结果可能最多是两个输入长度之和（考虑999 * 999的情况），所以+1是不需要的。  
    printf("请输入第一个乘数: ");
    scanf("%s", num1);
    printf("请输入第二个乘数: ");
    scanf("%s", num2);
    bigNumberMultiply(num1, num2, result);
    printf("两数之积为: %s\n", result);
    return 0;
}


void bigNumDivide(char* num1, char* num2, char* result) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);

    // 如果被除数小于除数，结果为0
    if (len1 < len2 || (len1 == len2 && strcmp(num1, num2) < 0)) {
        result[0] = '0';
        result[1] = '\0';
        return;
    }

    // 初始化结果数组为全'0'
    memset(result, '0', len1);
    result[len1] = '\0'; // 设置字符串结束标志

    // 反转两个字符串，方便从高位开始除
    reverse(num1);
    reverse(num2);

    // 进行除法运算
    for (int i = 0; i < len1 - len2 + 1; i++) {
        // 计算当前位的商
        int quotient = 0;
        while (compare(num1 + i, num2, len2) >= 0) {
            subtract(num1 + i, num2, len2);
            quotient++;
        }
        result[len1 - i - 1] = quotient + '0';
    }

    // 去除结果字符串开头的'0'（如果有的话）
    int index = 0;
    while (result[index] == '0' && index < len1 - 1) {
        index++;
    }
    if (index > 0) {
        memmove(result, result + index, len1 - index);
    }

    // 翻转回来得到最终结果
    reverse(result);
}

// 比较两个字符串的大小
int compare(char* num1, char* num2, int len) {
    for (int i = 0; i < len; i++) {
        if (num1[i] < num2[i]) {
            return -1;
        }
        else if (num1[i] > num2[i]) {
            return 1;
        }
    }
    return 0;
}

// 从num1中减去num2
void subtract(char* num1, char* num2, int len) {
    int borrow = 0;
    for (int i = 0; i < len; i++) {
        int digit1 = num1[i] - '0';
        int digit2 = num2[i] - '0';
        int diff = digit1 - digit2 - borrow;
        borrow = diff < 0 ? 1 : 0;
        diff = (diff + 10) % 10;
        num1[i] = diff + '0';
    }
    while (len > 0 && num1[len - 1] == '0') {
        len--;
    }
}

// 反转字符串
void reverse(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}
//int main() {
//    char dividend[MAX_LEN];  // 被除数  
//    char divisor[MAX_LEN];   // 除数  
//    char quotient[MAX_LEN];  // 商  
//    printf("请输入被除数：");
//    scanf("%s", dividend);  // 注意这里输入的是字符串形式的大数，不要包含空格或其他非数字字符  
//    printf("请输入除数：");
//    scanf("%s", divisor);   // 注意这里输入的是字符串形式的大数，不要包含空格或其他非数字字符  
//    bigNumDivide(dividend, divisor, quotient);
//    printf("商为：%s\n", quotient);  // 输出商，注意结果中可能包含前导零（如果除不尽）和末尾的'\0'字符（C字符串的特性）  
//    return 0;
//}