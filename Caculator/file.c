#define  _CRT_SECURE_NO_WARNINGS
#include "major function.h"
FILE* file;
void fileadd(char re[100]) {
	file = fopen("record.txt", "a");
	if (file == NULL) {
		printf("%s\n", strerror(errno));
		return;
	}
	fprintf(file, re);
	fclose(file);
}
