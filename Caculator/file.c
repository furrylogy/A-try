#define  _CRT_SECURE_NO_WARNINGS
#include "major function.h"
FILE* file;
void fileadd(char re[1000]) {
	FILE* file;
	file = fopen("record.txt", "a");
	if (file == NULL) {
		printf("%s\n", strerror(errno));
		return;
	}
	fprintf(file, re);
	fclose(file);
}
void fileget() {
	FILE* file;
	file = fopen("record.txt", "r"); char an[100];
	if (file == NULL) {
		printf("%s\n", strerror(errno));
		return;
	}
	int count = 0;
	while (fgets(an, sizeof(an), file) != NULL && count < 50) {
		printf("%s\n", an);
		count++;
	
	}
	printf("读取完毕或无记录\n");
	fclose(file);
}
void filedelete() {
	FILE* file;
	file = fopen("record.txt", "w");
	fclose(file);
}
 

//void print_file_content(const char* filename) {
//	FILE* file = fopen(filename, "r");
//	if (file == NULL) {
//		printf("无法打开文件 %s\n", filename);
//		return;
//	}
//
//	char line[256];
//	int count = 0;
//	while (fgets(line, sizeof(line), file) != NULL && count < 50) {
//		printf("%s", line);
//		count++;
//	}
//
//	fclose(file);
//}

