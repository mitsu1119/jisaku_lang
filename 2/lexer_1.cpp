#include <stdio.h>
#include <stdlib.h>

#define MAX_TEXT 100

void error(const char *str) {
	fprintf(stderr, str);
	exit(1);
}

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

			switch(c) {
				case '+':
					printf("PLUS ");
					break;
				case '-':
					printf("MINUS ");
					break;
				default:
					error("syntax error\n");
			}

			text[text_cnt++] = c;
		}

		text[text_cnt] = 0;
		printf("\n");
	}

	return 0;
}
