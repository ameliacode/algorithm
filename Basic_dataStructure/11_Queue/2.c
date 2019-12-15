#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef int element;

int quit = 0;

typedef struct DQNode {
	element data;
	struct DQNode *prev;
	struct DQNode *next;
}Deque;

typedef struct {
	Deque *front, *rear;
}DQType;

DQType *createDQ() {
	DQType *DQ;
	DQ = (DQType*)malloc(sizeof(DQType));
	DQ->front = NULL;
	DQ->rear = NULL;
	return DQ;
}

int isEmpty(DQType* DQ) {
	if (DQ->front == NULL) {
		printf("underflow");
		quit = 1;
		return 1;
	}
	else return 0;
}

void add_front(DQType *DQ, element item) {
	Deque *newNode = (Deque*)malloc(sizeof(Deque));
	newNode->data = item;
	if (DQ->front == NULL) {
		DQ->front = newNode;
		DQ->rear = newNode;
		newNode->next = NULL;
		newNode->prev = NULL;
	}
	else {
		DQ->front->prev = newNode;
		newNode->next = DQ->front;
		newNode->prev = NULL;
		DQ->front = newNode;
	}
}

void add_rear(DQType* DQ, element item) {
	Deque *newNode = (Deque*)malloc(sizeof(Deque));
	newNode->data = item;
	if (DQ->front == NULL) {
		DQ->front = newNode;
		DQ->rear = newNode;
		newNode->next = NULL;
		newNode->prev = NULL;
	}
	else {
		DQ->rear->next = newNode;
		newNode->next = NULL;
		newNode->prev = DQ->rear;
		DQ->rear = newNode;
	}
}

void delete_front(DQType *DQ) {
	Deque *old = DQ->front;
	element item;
	if (isEmpty(DQ)) return 0;
	else {
		item = old->data;
		if (DQ->front->next == NULL) {
			DQ->front = NULL;
			DQ->rear = NULL;
		}
		else {
			DQ->front = DQ->front->next;
			DQ->front->prev = NULL;
		}
		free(old);
		//return item;
	}
}

void delete_rear(DQType* DQ) {
	Deque *old = DQ->rear;
	element item;
	if (isEmpty(DQ)) return 0;
	else {
		item = old->data;
		if (DQ->rear->prev == NULL) {
			DQ->front = NULL;
			DQ->rear = NULL;
		}
		else {
			DQ->rear = DQ->rear->prev;
			DQ->rear->next = NULL;
		}
		free(old);
		//return item;
	}
}

void printDQ(DQType *DQ) {
	Deque *temp = DQ->front;
	while (temp) {
		printf(" %d", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main() {
	Deque *DQ = createDQ();
	int oper;
	int data;
	char judge[3]="";

	scanf("%d", &oper);
	while (oper) {
		scanf("%s", judge);
		getchar();
		if(!strcmp(judge, "AF")) {
			scanf("%d", &data);
			getchar();
			add_front(DQ, data); oper--;
		}
		else if (!strcmp(judge, "AR")) {
			scanf("%d", &data);
			getchar();
			add_rear(DQ, data); oper--;
		}
		else if (!strcmp(judge, "DF")) {
			delete_front(DQ); oper--;
		}
		else if (!strcmp(judge, "DR")) {
			delete_rear(DQ); oper--;
		}
		else if (!strcmp(judge, "P")) {
			printDQ(DQ); oper--;
		}
		if (quit) break;
	}
}
