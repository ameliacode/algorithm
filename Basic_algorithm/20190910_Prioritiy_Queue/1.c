#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void SwapElements(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void inPlaceSelectionSort(int A[], int N) {
	int pass, maxLoc, i, j;

	for (pass = N - 1; pass >= 0; pass--) {
		maxLoc = pass;
		for (j = 0; j < pass; j++) {
			if (A[j] > A[maxLoc]) {
				maxLoc = j;
			}
		}
		SwapElements(&A[pass], &A[maxLoc]);
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

	inPlaceSelectionSort(a, N);

	return 0;
}
