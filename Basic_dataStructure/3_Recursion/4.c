#include<stdio.h>
#include<string.h>

int Max(int A[], int n)
{
	if (n == 0)
		return A[0];
	else {
		int xmax = Max(A, n - 1);
		if (xmax < A[n]) xmax = A[n];
		return xmax;
	}
}

int main()
{
	int N, i, result = 0;
	int A[20] = { '/0', };

	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}

	result = Max(A, N - 1);
	printf("%d", result);

	return 0;
}
