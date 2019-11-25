#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int n;

void merge(int *A, int l, int m, int r) {
	int i = l;
	int k = l;
	int j = m + 1;
	int *B = (int*)malloc(sizeof(int)*n);

	while (i <= m && j <= r) {
		if (*(A + i) <= *(A + j)) {
			B[k++] = A[i++];
		}
		else {
			B[k++] = A[j++];
		}
	}
	while (i <= m) {
		B[k++] = A[i++];
	}
	while (j <= r) {
		B[k++] = A[j++];
	}
	for (k = l; k <= r; k++) {
		*(A + k) = *(B + k);
	}
	return;
}

void rMergeSort(int *A, int l, int r) {
	
	int m;

	if (l < r) {
		m = (l + r) / 2;
		rMergeSort(A, l, m);
		rMergeSort(A, m + 1, r);
		merge(A, l, m, r);
	}

	return;
}

void mergeSort(int *A) {

	rMergeSort(A, 0, n - 1);
	return;
}

void printArray(int *A) {
	int i;
	for (i = 0; i < n; i++) {
		printf(" %d", *(A + i));
	}
}

int main(void) {
	
	int *L;
	int i;

	scanf("%d", &n);

	L = (int*)malloc(sizeof(int)*n);

	for (i = 0; i < n; i++) {
		scanf("%d", &L[i]);
	}
	mergeSort(L);
	printArray(L);

	return 0;
}//copyright github @ameliacode 2019
