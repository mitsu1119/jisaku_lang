#include <stdio.h>

#define MAX_TEXT 100

bool isspace(char c) {
	if(c == ' ' || c == '	') return true;
	return false;
}

int main() {
	char c;
	char text[MAX_TEXT] = {0};
	int text_cnt;

	while(true) {
		text_cnt = 0;
		printf(">> ");
		while(true) {
			c = getc(stdin);

			if(c == '\n') break;
			if(isspace(c)) continue;
			text[text_cnt++] = c;
		}

		text[text_cnt] = 0;
		printf("%s\n", text);
	}

	return 0;
}
