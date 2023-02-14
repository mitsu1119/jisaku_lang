#include <stdio.h>
#include <stdlib.h>

#define MAX_TEXT 100

void error(char *text) {
	fprintf(stderr, text);
	exit(0);
}

bool isspace(char c) {
	if(c == ' ' || c == '	') return true;
	return false;
}

bool isdigit(char c) {
	if(c >= '0' && c <= '9') return true;
	return false;
}

bool isop(char c) {
	if(c == '+' || c == '*' || c == '-' || c == '/') return true;
	return false;
}

bool isend(char c) {
	if(c == '\n') return true;
	return false;
}

int numberL() {
	char c;
	char text[MAX_TEXT] = {0};
	int text_cnt, res;

	text_cnt = 0;
	while(true) {
		c = getc(stdin);

		if(isspace(c)) {
			if(text_cnt != 0) break;
			continue;
		}

		if(isdigit(c)) text[text_cnt++] = c;
		else error("sytax error\n");
	}

	res = strtol(text, NULL, 10);
	return res;
}

char operation() {
	char c;
	char text[MAX_TEXT] = {0};
	int text_cnt;

	text_cnt = 0;
	while(true) {
		c = getc(stdin);
		if(isspace(c)) {
			if(text_cnt != 0) break;
			continue;
		}

		if(isop(c)) text[text_cnt++] = c;
		else error("syntax error\n");
	}

	if(text_cnt != 1) error("syntax error\n");
	return text[0];
}

int numberR() {
	char c;
	char text[MAX_TEXT] = {0};
	int text_cnt, res;

	text_cnt = 0;
	while(true) {
		c = getc(stdin);

		if(isspace(c)) continue;

		if(isend(c)) {
			if(text_cnt == 0) error("syntax error\n");
			break;
		}

		if(isdigit(c)) text[text_cnt++] = c;
		else error("sytax error\n");
	}

	res = strtol(text, NULL, 10);
	return res;
}

int main() {
	while(true) {
		printf(">> ");
		
		int numL = numberL();
		char op = operation();
		int numR = numberR();

		printf("%d %c %d = ", numL, op, numR);
		switch(op) {
		case '+':
			printf("%d\n", numL + numR);
			break;
		case '-':
			printf("%d\n", numL - numR);
			break;
		case '*':
			printf("%d\n", numL * numR);
			break;
		case '/':
			printf("%d\n", numL / numR);
			break;
		}
	}

	return 0;
}
