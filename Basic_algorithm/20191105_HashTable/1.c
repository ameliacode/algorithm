#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct bucket {
	int key;
	int element[10];
}Bucket;

int M;
Bucket *A;

int h(int x) {
	return x % M;
}

void initBucketArray() {

	int i, j;
	A = (Bucket*)malloc(sizeof(Bucket)*M);
	for (i = 0; i < M; i++) {
		for (j = 0; j < 10; j++) {
			(A + i)->key = 0;
			(A + i)->element[j] = NULL;
		}
	}
	return;
}

int findElement(int k) {
	int v = h(k);
	int i;

	for (i = 0; i < 10; i++) {
		if ((A + v)->element[i] == k)
			return (A + v)->key - i;
	}
	return 0;
}

void insertItem(int k) {
	int v = h(k);
	int key = (A + v)->key;
	int temp;

	(A + v)->element[key] = k;
	(A + v)->key++;
}

int removeElement(int k) {
	int v = h(k);
	int i, result;
	for (i = 0; i < 10; i++) {
		if ((A + v)->element[i] == k) {
			(A + v)->element[i] = NULL;
			result = (A + v)->key - i;
			(A + v)->key--;
			return result;
		}
	}
	return 0;
}

void printArray() {
	int i, j;
	for (i = 0; i < M; i++) {
		for (j = (A + i)->key; j >= 0; j--) {
			if ((A + i)->element[j] != NULL) {
				printf(" %d", (A + i)->element[j]);
			}
		}
	}
	printf("\n");
}


int main() {

	int element;
	int m;
	int operating = 1;
	char oper;


	scanf("%d", &M);
	getchar();
	m = M;
	initBucketArray();

	while (operating) {

		scanf("%c", &oper);
		switch (oper) {
		case 'i':
			scanf("%d", &element);
			getchar();
			insertItem(element);
			break;

		case 's':
			scanf("%d", &element);
			getchar();
			printf("%d\n", findElement(element));
			break;

		case 'd':
			scanf("%d", &element);
			printf("%d\n", removeElement(element));
			break;

		case 'p':
			printArray();
			break;

		case 'e':
			operating = 0;
			break;

		}
	}

	return 0;

}//copyright github @ameliacode 2019
