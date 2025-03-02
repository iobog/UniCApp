#pragma once
#include <string.h>
#include <assert.h>

void trimTrailing(char* str) {
	int i, poz = -1;
	for (i = 0; i < strlen(str); i++) {
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			poz = i;
	}
	str[poz + 1] = '\0';
}
void test() {
	char str1[] = "Hello world    ";
	trimTrailing(str1);
	assert(strcmp(str1, "Hello world") == 0);

	char str2[] = "Niciun spatiu";
	trimTrailing(str2);
	assert(strcmp(str2, "Niciun spatiu") == 0);
}