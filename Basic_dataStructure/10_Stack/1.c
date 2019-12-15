#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define STACK_SIZE 500

char stack[STACK_SIZE];
int top = -1;
int stack_size = 0;

int isEmpty() {
	if (top == -1) return 1;
	else return 0;
}

int isFull() {
	if (top == stack_size - 1) return 1;
	else return 0;
}

void push(char item) {
	if (isFull()) {
		printf("Stack FULL\n");
		return;
	}
	else stack[++top] = item;
}

char pop() {
	if (isEmpty()) {
		printf("Stack Empty\n");
		return;
	}
	else return stack[top--];
}

void peek() {
	if (isEmpty()) {
		printf("Stack Empty\n");
		return;
	}
	else {
		printf("%c",stack[top]);
		return;
	}
}

void printStack() {
	int i;
	for (i = top; i >= 0; i--) {
		printf("%c", stack[i]);
	}
	printf("\n");
}

void upRotate(int n) {
	if (top + 1 < n) return;
	int i;
	char temp = stack[top];
	for (i = top; i >= top - n + 1; i--) {
		stack[i] = stack[i - 1];
	}
	stack[top - n + 1] = temp;
}

void downRotate(int n) {
	if (top + 1 < n) return;
	int i;
	char temp = stack[top - n + 1];
	for (i = top - n + 1; i < top; i++) {
		stack[i] = stack[i + 1];
	}
	stack[top] = temp;
}

void duplicate() {
	if (isEmpty()) {
		printf("Stack Empty\n");
		return;
	}
	char dup = pop();
	push(dup);
	push(dup);
	return;
}

int main() {
	int oper;
	int num;
	char judge[6] = "";
	char data;
	scanf("%d", &stack_size);
	scanf("%d", &oper);
	getchar();
	//printf("%d %d", stack_size, oper);
	while (oper) {
		scanf("%s", judge);
		getchar();
		//printf("operating\n");
		if (strcmp(judge, "POP")==0) {
			pop();
			oper--;
		}
		else if (strcmp(judge, "PUSH")==0) {
			scanf("%c", &data);
			getchar();
			push(data);
			oper--;
		}
		else if (strcmp(judge, "PEEK")==0) {
			peek();
			oper--;
		}
		else if (strcmp(judge, "DUP")==0) {
			duplicate();
			oper--;
		}
		else if (strcmp(judge, "UpR")==0) {
			scanf("%d", &num);
			getchar();
			upRotate(num);
			oper--;
		}
		else if (strcmp(judge, "DownR")==0) {
			scanf("%d", &num);
			getchar();
			downRotate(num);
			oper--;
		}
		else if (strcmp(judge, "PRINT")==0) {
			printStack();
			oper--;
		}
	}

	return 0;
}
