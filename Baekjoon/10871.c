#include<stdio.h>
#include<stdlib.h>

int main()
{
	int N, X;
	int i;
	int *input;
	
	scanf("%d %d", &N, &X);
	input = (int*)malloc(N * sizeof(int));

	for (i = 0; i < N; i++)
		scanf("%d", &input[i]);
	for (i = 0; i < N; i++)
		if (input[i] < X) printf("%d ", input[i]);

	return 0;
}