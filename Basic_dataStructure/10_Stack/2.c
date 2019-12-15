#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define STACK_SIZE 100

typedef int element;

element stack[STACK_SIZE];
int top = -1;
int stack_size = 100;

int isEmpty() {
	if (top == -1) return 1;
	else return 0;
}

int isFull() {
	if (top == stack_size - 1) return 1;
	else return 0;
}

void push(element item) {
	if (isFull()) {
		//printf("Stack FULL\n");
		return;
	}
	else stack[++top] = item;
}

element pop() {
	if (isEmpty()) {
		//printf("Stack Empty\n");
		return;
	}
	else return stack[top--];
}

element peek() {
	if (isEmpty()) {
		//printf("Stack Empty\n");
		return;
	}
	else {
		//printf("%c",);
		return stack[top];
	}
}

void printStack() {
	int i;
	for (i = top; i >= 0; i--) {
		printf("%d", stack[i]);
	}
	printf("\n");
}

void calculation(char input[]){
	int result;
	int i;
	int a, b;
	int len = strlen(input);
	
	//printf("Calculating\n");
	for (i = 0; i < len; i++)
	{
		if ('0' <= input[i] && input[i] <= '9') {
			//printf("Calculating\n");
			push(input[i]-'0');
			//printStack();
		}
		else {
			a = pop();
			b = pop();
			if (input[i] == '*') result = a * b;
			if (input[i] == '/') result = b / a;
			if (input[i] == '+') result = a + b;
			if (input[i] == '-') result = b - a;
			push(result);
		}
	}
	printf("%d\n", peek());
	//result = peek();
	while (top != -1) {
		pop();
	}
	return;
}


int main() {
	int oper;
	int result;
	char calc[101] = "";
	scanf("%d", &oper);

	while (oper) {
		scanf("%s", calc);
		calculation(calc);
		//printf("%d\n", result);
		oper--;
	}

	return 0;
}
