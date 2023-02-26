#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT 100

void error(const char *str) {
	fprintf(stderr, str);
	exit(1);
}

bool isspace(char c) {
	if(c == ' ' || c == '	') return true;
	return false;
}

bool isalpha(char c) {
	if(c >= 'A' && c <= 'Z') return true;
	if(c >= 'a' && c <= 'z') return true;
	return false;
}

int main() {
	char c;
	char text[MAX_TEXT] = {0};
	int text_cnt;

	// interpreter loop
	while(true) {
		printf(">> ");

		// tokens loop
		while(true) {
			c = getc(stdin);

			if(isspace(c)) continue;
			if(c == '\n') {
				printf("\n");
				break;
			}

			// input token loop
			text_cnt = 0;
			if(isalpha(c)) {
				do {
					text[text_cnt++] = c;
					c = getc(stdin);
				} while(isalpha(c));

				text[text_cnt] = 0;
				ungetc(c, stdin);
				
				if(!strcmp(text, "aa")) printf("AA ");
				else if(!strcmp(text, "bb")) printf("BB ");
				else error("syntax error\n");
			} else {
				error("syntax error\n");
			}
		}
	}

	return 0;
}
