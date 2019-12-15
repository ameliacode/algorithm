#include<stdio.h>
#include<stdlib.h>

typedef struct listNode {
	int elem;
	struct listNode* next;
}Node;

typedef struct {
	Node *head;
}Header;

Header *CreateList(void) {
	Header *DL;
	DL = (Header*)malloc(sizeof(Header));
	DL->head = NULL;
	return DL;
}

void addList(Header *list, int data) {
	Node *newNode;
	Node *temp;
	newNode = (Node*)malloc(sizeof(Node));
	newNode->next = NULL;
	newNode->elem = data;
	
	if (list->head == NULL) {
		list->head = newNode;
	}
	else {
		temp = list->head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newNode;
	}
}

int Subset(Header* a, Header *b, int aSize, int bSize)
{//n(A)<n(B)
	Node *aTmp, *bTmp;
	int elem = 0;
	aTmp = a->head;
	bTmp = b->head;
	
	if (aSize <= bSize) {
		while (!aTmp == NULL) {
			if (aTmp->elem > bTmp->elem) {
				bTmp = bTmp->next;
				if (bTmp == NULL) return aTmp->elem;
			}
			else if (aTmp->elem == bTmp->elem) {
				aTmp = aTmp->next;
				bTmp = bTmp->next;
			}
			else if (aTmp->elem < bTmp->elem) {
				return aTmp->elem;
			}
		}
	}
	else {
		while (!aTmp == NULL) {
			if (aTmp->elem > bTmp->elem) {
				bTmp = bTmp->next;
			}
			else if (aTmp->elem == bTmp->elem) {
				aTmp = aTmp->next;
				bTmp = bTmp->next;
			}
			else if (aTmp->elem < bTmp->elem) {
				return aTmp->elem;
			}
			if (bTmp == NULL) return aTmp->elem;
		}
	}
	return elem;
}

void printList(Header *list) {
	Node *temp = list->head;
	while (temp != NULL) {
		printf("%d\n", temp->elem);
		temp = temp->next;
	}
}

Header* Union() {

}

Header* Intersect() {

}

int main() {
	Header *A, *B, *C;
	Node *aTmp, *bTmp;
	int aSize, bSize;
	int elem;
	int i, judge;

	A = CreateList();
	B = CreateList();
	C = CreateList();

	scanf("%d", &aSize);
	
	for (i = 0; i < aSize; i++) {
		scanf("%d", &elem);
		addList(A, elem);
	}

	scanf("%d", &bSize);
	for (i = 0; i < bSize; i++) {
		scanf("%d", &elem);
		addList(B, elem);
	}

	if (aSize == 0) {
		printf("0\n");
	}
	else if (bSize == 0) {
		printf("%d\n", A->head->elem);
	}
	else {
		printf("%d\n", Subset(A, B, aSize, bSize));
	}

	return 0;
}
