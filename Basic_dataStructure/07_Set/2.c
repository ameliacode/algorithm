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
	Node *temp;
	temp = list->head;
	while (temp != NULL) {
		printf(" %d", temp->elem);
		temp = temp->next;
	}
	printf("\n");
}

Header* Union(Header *A, Header *B) {
	Node *aTmp, *bTmp;
	Header *C;
	Node* temp;

	aTmp = A->head;
	bTmp = B->head;

	C = CreateList();

	//printf("Start Union\n");
	while (1) {
		//printf("let's union\n");
		if (aTmp->elem < bTmp->elem) {
			addList(C, aTmp->elem);
			aTmp = aTmp->next;
			//printf("!\n");
		}
		else if (aTmp->elem == bTmp->elem) {
			addList(C, aTmp->elem);
			aTmp = aTmp->next;
			bTmp = bTmp->next;
			//printf("!!\n");
		}
		else if (aTmp->elem > bTmp->elem) {
			addList(C, bTmp->elem);
			bTmp = bTmp->next;
			//printf("!!!\n");
		}
		//printList(C);
		//printf("count\n");
		if (aTmp==NULL || bTmp==NULL) break;
	}
	//printf("leftovers\n");
	if (aTmp == NULL && bTmp != NULL) {
		while (bTmp!=NULL) {
			addList(C, bTmp->elem);
			bTmp = bTmp->next;
		}
	}
	else if (bTmp == NULL && aTmp != NULL) {
		while (aTmp!=NULL) {
			addList(C, aTmp->elem);
			aTmp = aTmp->next;
		}
	}
	return C;
}

Header* Intersect(Header *A, Header *B) {
	Node *aTmp, *bTmp;
	Header *C;
	Node* temp;

	aTmp = A->head;
	bTmp = B->head;

	C = CreateList();

	while (1) {
		if (aTmp->elem < bTmp->elem) {
			aTmp = aTmp->next;
		}
		else if (aTmp->elem == bTmp->elem) {
			addList(C, aTmp->elem);
			aTmp = aTmp->next;
			bTmp = bTmp->next;
		}
		else if (aTmp->elem > bTmp->elem) {
			bTmp = bTmp->next;
		}
		if (aTmp == NULL || bTmp == NULL) break;
	}
	return C;
}

int main() {
	Header *A, *B, *C, *D;
	Node *aTmp, *bTmp;
	int aSize, bSize;
	int elem;
	int i, judge;

	A = CreateList();
	B = CreateList();
	C = CreateList();
	D = CreateList();

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

	//Subset
	/*if (aSize == 0) {
		printf("0\n");
	}
	else if (bSize == 0) {
		printf("%d\n", A->head->elem);
	}
	else {
		printf("%d\n", Subset(A, B, aSize, bSize));
	}*/

	//Union, intersect

	if (aSize == 0 && bSize == 0) {
		printf(" 0\n 0\n");
	}
	else if (aSize == 0 || bSize == 0) 
	{
		if (aSize == 0) {
			printList(B);		//union
			printf(" 0\n");		//intersect
		}
		else if(bSize == 0){
			printList(A);
			printf(" 0\n");
		}	
	}
	else {
		C = Union(A, B);
		printList(C);
		D = Intersect(A, B);
		printList(D);
	}


	return 0;
}
