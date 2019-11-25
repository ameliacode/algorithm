#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct bucket {
	int key;
	int element;
}Bucket;

Bucket *A;
int M, q;

int h(int x) {
	return x % M;
}

int h2(int x) {
	return q - x % q;
}

int isEmpty(Bucket *A) {
	if (A->key == 0)
		return 1;
	else
		return 0;
}

void initBucketArray() {

	int i, j;
	A = (Bucket*)malloc(sizeof(Bucket)*M);
	for (i = 0; i < M; i++) {
		(A + i)->key = 0;
		(A + i)->element = 0;
	}
	return;
}

int getNextBucket(int v, int i, int k) {
	return (v + i * h2(k)) % M;
}

void insertItem(int k) {
	int v = h(k);
	int i = 0;
	int b, j;
	while (i < M) {
		b = getNextBucket(v, i, k);
		if (isEmpty(A + b)) {
			(A + b)->key = k;
			for (j = 0; j < i; j++) {
				printf("C");
			}
			printf("%d\n", b);
			(A + b)->element++;
			return;
		}
		else {
			i++;
		}
	}
	//overflowException();
	return;
}

void findElement(int k) {
	int v = h(k);
	int i = 0;
	int b;
	while (i < M) {
		b = getNextBucket(v, i, k);
		if (isEmpty(A + b)) {
			printf("-1\n");
			return;
		}
		else if (k == (A + b)->key) {
			printf("%d %d\n", b, (A + b)->key);
			return;
		}
		else
			i++;
	}
	printf("-1\n");
}

void printArray() {
	int i;
	for (i = 0; i < M; i++) {
		printf(" %d", (A + i)->key);
	}
	printf("\n");
}


int main() {

	int n;
	int working = 1;
	char oper;
	int key;

	scanf("%d %d %d", &M, &n, &q);
	getchar();

	initBucketArray();

	while (working) {
		scanf("%c", &oper);
		getchar();
		switch (oper) {
		case 'i':
			scanf("%d", &key);
			getchar();
			insertItem(key);
			break;
		case's':
			scanf("%d", &key);
			getchar();
			findElement(key);
			break;
		case 'p':
			printArray();
			break;
		case 'e':
			working = 0;
			printArray();
			break;
		}
	}

	return 0;
}