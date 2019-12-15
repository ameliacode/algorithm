#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//total rank for searching
int total = 0;

typedef struct listNode {
	char elem;
	int rank;
	struct listNode *prev;
	struct listNode *next;
}Node;

typedef struct {
	Node *head;
}Header;

Header* CreateList(void) {
	Header* DL;
	DL = (Header*)malloc(sizeof(Header));
	DL->head = NULL;
	return DL;
}

void Add(Header *list, int rank, char data);
void Delete(Header *list, int rank);
void Get(Header *list, int rank);
void Print(Header *list);

void Add(Header *list, int rank, char data) {
	Node *newNode;
	Node *temp;
	newNode = (Node*)malloc(sizeof(Node));
	newNode->prev = NULL;
	newNode->next = NULL;
	newNode->elem = data;
	newNode->rank = rank;

	if (rank > total + 1) {
		printf("invalid position\n");
		return;
	}

	total++;

	if (list->head == NULL) {
		list->head = newNode;
	}
	else if (rank == 1) {			//add first node
		temp = list->head;
		newNode->next = temp;
		temp->prev = newNode;
		list->head = newNode;

		temp = newNode->next;
		while (temp != NULL) {
			temp->rank++;
			temp = temp->next;
		}
	}
	else {
		//printf("!\n");
		temp = list->head;
		//printf("temp rank: %d!!\n", temp->rank);
		while (temp->rank != rank - 1) {
			//printf("temp rank: %d!!\n", temp->rank);
			temp = temp->next;
		}
		//printf("Done!!\n");
		if (temp->next != NULL) {
			newNode->next = temp->next;
			temp->next->prev = newNode;
			temp->next = newNode;
			newNode->prev = temp;
			//printf("Done2!!\n");
			temp = newNode->next;
			//if (temp != NULL) printf("%c\n", temp->elem);
			while (temp != NULL) {
				temp->rank++;
				temp = temp->next;
			}
		}
		else if(temp->next==NULL){
			temp->next = newNode;
			newNode->prev = temp;
		}
	}
}

void Delete(Header *list, int rank) {
	Node *temp;
	Node *p;

	temp = list->head;
	p = list->head;

	if (list->head == NULL || total < rank || total == 0) {
		printf("invalid position\n");
		return;
	}
	else if (rank == 1) {			//delete first node
		p = p->next;
		temp->next = NULL;
		total--;
		if (p == NULL) list->head = NULL;
		else {
			p->prev = NULL;
			list->head = p;
			while (p != NULL) {
				p->rank--;
				p = p->next;
			}
		}
		free(temp);
		free(p);
	}
	else {
		total--;
		//printf("Let's Delete\n");

		while (temp->rank != rank) {
			temp = temp->next;
			p = p->next;
		}
		if (temp == NULL) {
			printf("invalid position\n");
			return;
		}
		else {
			//printf("Deleting...\n");
			//printf("Deleting: %c\n", temp->elem);
			//printf("Previous elem: %c\n", temp->prev->elem);
			temp->prev->next = temp->next;
			if (temp->next != NULL)temp->next->prev = temp->prev;
			//printf("Deleting: %c\n", temp->elem);

			p = p->next;
			while (p != NULL) {
				p->rank--;
				p = p->next;
			}
			free(temp);
			free(p);
		}
	}
}

void Get(Header *list, int rank) {
	Node *temp;
	temp = list->head;
	if (list->head == NULL || total < rank) {
		printf("invalid position\n");
		return;
	}
	else {
		while (temp->rank != rank) {
			temp = temp->next;
		}
		if (temp == NULL) {
			printf("invalid position\n");
			return;
		}
		else {
			printf("%c\n", temp->elem);
		}
	}
}

void Print(Header *list) {
	Node* temp;
	temp = list->head;
	while (temp != NULL) {
		printf("%c", temp->elem);
		//printf("%c %d\n", temp->elem, temp->rank);
		temp = temp->next;
	}
	printf("\n");
}

int main() {

	Header* DL;
	Node *p;
	DL = CreateList();
	int N, rank;
	char judge, data;

	scanf("%d", &N);
	getchar();
	while (N) {
		//printf("Operating!!\n");
		scanf("%c", &judge);
		getchar();
		if (judge == 'A') {
			//printf("Adding...\n");
			scanf("%d %c", &rank, &data);
			getchar();
			Add(DL, rank, data);
		}
		else if (judge == 'D') {
			//printf("Deleting...\n");
			scanf("%d", &rank);
			getchar();
			Delete(DL, rank);
		}
		else if (judge == 'G') {
			//printf("Searching...\n");
			scanf("%d", &rank);
			getchar();
			Get(DL, rank);
		}
		else if (judge == 'P') {
			//printf("Printing...\n");
			Print(DL);
		}
		N--;
		//printf("total: %d\n", total);
	}

	getchar();
	return 0;
}
