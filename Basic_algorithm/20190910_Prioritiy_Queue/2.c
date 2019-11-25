#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void inPlaceInsertionSort(int A[], int N) {
	int pass, i, j, save;

	for (pass = 1; pass < N; pass++) {
		save = A[pass];
		j = pass - 1;
		while ((j >= 0) && (A[j] > save)) {
			A[j + 1] = A[j];
			j = j - 1;
		}
		A[j + 1] = save;
	}

	for (i = 0; i < N; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");
}

int main()
{
	int N, i;
	int *a;

	scanf("%d", &N);
	a = (int*)malloc(sizeof(int)*N);

	for (i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}

	inPlaceInsertionSort(a, N);

	return 0;
}//copyright github @ameliacode 2019
