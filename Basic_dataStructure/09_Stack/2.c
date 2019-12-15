#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef char element;
int count = 0;

typedef struct stackNode {
	element data;
	struct stackNode *link;
}stackNode;

stackNode *top;

int isEmpty() {
	if (top == NULL) return 1;
	else return 0;
}

void push(element item) {
	stackNode *temp = (stackNode*)malloc(sizeof(stackNode));
	temp->data = item;
	temp->link = top;
	top = temp;
}

element pop() {
	element item;
	stackNode *temp = top;

	if (top == NULL) {
		printf("Stack Empty\n");
		return;
	}
	else {
		item = temp->data;
		top = temp->link;
		free(temp);
		return item;
	}
}

int testPair(char *exp) {
	char symbol, open_pair;
	int i, length = strlen(exp);
	top = NULL;

	for (i = 0; i < length; i++) {
		symbol = exp[i];
		switch (symbol) {
		case '(':
		case '[':
		case '{':
			push(symbol);  break;
		case ')':
		case '}':
		case ']':
			if (top == NULL) return 0;
			else {
				open_pair = pop();
				if ((open_pair == '(' && symbol != ')') ||
					(open_pair == '[' && symbol != ']') ||
					(open_pair == '{' && symbol != '}'))
					return 0;
				else break;
			}
		}
	}
	if (top == NULL) return 1;
	else return 0;
}

void EraseSpace(char *exp) {
	char temp[1001] = "";
	int i, ind = 0;

	//printf("init Erasing\n");
	for (i = 0; exp[i] != 0; i++) {
		if (exp[i] != ' ') {
			temp[ind] = exp[i];
			ind++;
		}
		if (exp[i] == '(' ||
			exp[i] == '{' ||
			exp[i] == '[' ||
			exp[i] == ')' ||
			exp[i] == '}' ||
			exp[i] == ']') count++;
	}
	temp[ind] = 0;
	ind = 0;

	//printf("Erasing\n");
	for (i = 0; i < strlen(exp); i++) exp[i] = NULL;
	for (i = 0; temp[i] != 0; i++) {
		exp[ind] = temp[i];
		ind++;
	}
	exp[ind] = 0;
}

int main() {
	char input[1001] = "";
	gets(input);
	//getchar();
	EraseSpace(input);
	if (strlen(input)==0) {
		printf("Wrong_0\n");
	}
	else if (testPair(input) == 0) {
		printf("Wrong_%d\n", count);
	}
	else {
		printf("OK_%d\n", count);
	}

	return 0;
}
