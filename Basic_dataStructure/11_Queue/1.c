#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define cQ_SIZE	500

int qSize;
int quit = 0;
typedef int element;

typedef struct {
	element queue[cQ_SIZE];
	int front, rear;
}cQueue;

cQueue *createQueue() {
	cQueue *cQ;
	cQ = (cQueue*)malloc(sizeof(cQueue));
	cQ->front = 0;
	cQ->rear = 0;
	return cQ;
}

void initQ(cQueue *cQ);
int isEmpty(cQueue *cQ);
int isFull(cQueue *cQ);
void enQueue(cQueue *cQ, element item);
element deQueue(cQueue *cQ);
void del(cQueue *cQ);
element peek(cQueue *cQ);
void printQ(cQueue* cQ);

int main() {
	cQueue *cQ = createQueue();
	int oper;
	char judge;
	int data;

	scanf("%d", &qSize);
	scanf("%d", &oper);
	getchar();

	initQ(cQ);
	while (oper) {
		scanf("%c", &judge);
		getchar();

		switch (judge) {
		case 'I':
			scanf("%d", &data);
			getchar();
			enQueue(cQ, data);
			break;
		case 'D':
			del(cQ);
			break;
		case 'P':
			printQ(cQ);
			break;
		}
		if (quit) break;
		oper--;
	}
	return 0;
}

void initQ(cQueue *cQ) {
	int i = 0;
	for (i = 0; i < qSize; i++) {
		cQ->queue[i] = 0;
	}
}

int isEmpty(cQueue *cQ) {
	if (cQ->front == cQ->rear) {
		printf("underflow");
		quit = 1;
		return 1;
	}
	else return 0;
}

int isFull(cQueue *cQ) {
	if ((cQ->rear + 1) % (qSize) == cQ->front) {
		printf("overflow");
		quit = 1;
		return 1;
	}
	else return 0;
}

void enQueue(cQueue *cQ, element item) {
	if (isFull(cQ)) {
		printQ(cQ);
		return;
	}
	else {
		cQ->rear = (cQ->rear + 1) % qSize;
		cQ->queue[cQ->rear] = item;
	}
}

element deQueue(cQueue *cQ) {
	if (isEmpty(cQ)) return 0;
	else {
		cQ->front = (cQ->front + 1) % qSize;
		return cQ->queue[cQ->front];
	}
}

void del(cQueue *cQ) {
	if (isEmpty(cQ)) return;
	else {
		cQ->front = (cQ->front + 1) % qSize;
		cQ->queue[cQ->front] = 0;
	}
}

element peek(cQueue *cQ) {
	if (isEmpty(cQ)) return 0;
	else return cQ->queue[(cQ->front + 1) % qSize];
}

void printQ(cQueue* cQ) {
	int i, first, last;
	first = 0;
	last = qSize;
	i = first;
	while (i != last) {
		printf(" %d", cQ->queue[i]);
		i++;
	}
	printf("\n");
	//printf("%d %d", cQ->front, cQ->rear);
}
