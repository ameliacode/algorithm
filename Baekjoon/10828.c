#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define INF 99999999
#define SIZE 100000

int stack[SIZE];
int top = -1;
int Size = 0;

void push(int data)
{
	stack[++top] = data;
	Size++;
}

int getTop() {
	if (top == -1) return -1;
	else return stack[top];
}

int pop()
{
	if (top == -1) {
		return -1;
	}
	Size--;
	return stack[top--];
}

int empty() {
	//printf("result: ");
	if (Size <= 0) printf("1");
	else printf("0");
}

int main()
{
	int N;
	int element;
	int popResult;
	int topResult;
	char inst[6];

	scanf("%d", &N);
	getchar();
	while (N != 0) {
		scanf("%s", inst);
		if (!strcmp(inst, "push")) {
			scanf("%d", &element);
			push(element);
		}
		else if (!strcmp(inst, "pop")) {
			popResult = pop();
			printf("%d", popResult);
			printf("\n");
		}
		else if (!strcmp(inst, "size")) {
			printf("%d", Size);
			printf("\n");
		}
		else if (!strcmp(inst, "empty")) {
			empty();
			printf("\n");
		}
		else if (!strcmp(inst, "top")) {
			topResult = getTop();
			printf("%d", topResult);
			printf("\n");
		}
		N--;
	}

	return 0;
}