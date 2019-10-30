#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int n;

typedef struct listNode {
	int element;
	struct listNode *next;
}Node;

typedef struct {
	Node *head;
}Header;

typedef struct {
	Header *L1;
	Header *L2;
}DIV;

Header* CreateList(void) {
	Header *L;
	L = (Header*)malloc(sizeof(Header));
	L->head = NULL;
	return L;
}

DIV* CreateDiv(void) {
	DIV *div;
	div = (DIV*)malloc(sizeof(DIV));
	div->L1 = NULL;
	div->L2 = NULL;
	return div;
}

void addLast(Header *list, int element);
int removeFirst(Header *list);
int isEmpty(Header *L);
int Size(Header *L);
void printArray(Header *A);
DIV *partition(Header *L, int num);
Header* merge(Header *L1, Header *L2);
Header* mergeSort(Header *L);

int main(void) {

	Header *L = CreateList();
	int i;
	int element;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d", &element);
		addLast(L, element);
	}
	L = mergeSort(L);
	printArray(L);

	return 0;
}

void addLast(Header *list, int element) {
	Node *newNode;
	Node *temp = list->head;

	newNode = (Node*)malloc(sizeof(Node));
	newNode->next = NULL;
	newNode->element = element;
	if (list->head == NULL) {
		list->head = newNode;
	}
	else {
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newNode;
	}
}

int removeFirst(Header *list) {

	int temp_element;
	Node *temp;

	if (isEmpty(list)) {
		return;
	}
	else {
		temp = list->head;
		temp_element = list->head->element;
		list->head = temp->next;
		free(temp);
	}
	return temp_element;
}

int isEmpty(Header *L) {
	if (L->head == NULL) return 1;
	else return 0;
}

void printArray(Header *A) {

	Node *temp = A->head;
	if (temp == NULL) {
		printf("Empty List\n");
		return;
	}
	while (temp != NULL) {
		printf(" %d", temp->element);
		temp = temp->next;
	}
	printf("\n");
}

int Size(Header *L) {
	int nSize = 0;
	Node *temp = L->head;
	while (temp != NULL) {
		temp = temp->next;
		nSize++;
	}
	return nSize;
}

Header* merge(Header *L1, Header *L2) {
	Header *list = CreateList();
	//printf("merging: ");printArray(L1);
	//printArray(L2);
	while (!isEmpty(L1) && !isEmpty(L2)) {
		if (L1->head->element <= L2->head->element) {
			addLast(list, removeFirst(L1));
		}
		else {
			addLast(list, removeFirst(L2));
		}
	}
	while (!isEmpty(L1)) {
		addLast(list, removeFirst(L1));
	}
	while (!isEmpty(L2)) {
		addLast(list, removeFirst(L2));
	}
	return list;
}

Header *mergeSort(Header *L) {

	Header *L1 = NULL;
	Header *L2 = NULL;
	DIV *div = CreateDiv();
	if (Size(L) > 1) {
		div = partition(L, Size(L) / 2);
		L1 = div->L1;
		L2 = div->L2;
		//printArray(L1);
		//printArray(L2);
		L1 = mergeSort(L1);
		L2 = mergeSort(L2);
		L = merge(L1, L2);
		//printf("result:");printArray(L);
	}
	return L;
}

DIV* partition(Header *L, int k) {

	DIV *div = CreateDiv();
	Node *temp;
	Header *L1 = CreateList();
	Header *L2 = CreateList();
	int i;

	temp = L->head;
	L1 = L;
	for (i = 0; i < k - 1; i++) {
		temp = temp->next;
	}
	L2->head = temp->next;
	temp->next = NULL;
	div->L1 = L1;
	div->L2 = L2;

	return div;
}
