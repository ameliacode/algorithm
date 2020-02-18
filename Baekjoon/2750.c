#include<stdio.h>
#include<stdlib.h>

int main()
{
	int N, i, j;
	int *arr, tmp;

	scanf("%d", &N);
	//버블정렬
	arr = (int*)malloc(N * sizeof(int));
	for (i = 0; i < N; i++)
		scanf("%d",&arr[i]);

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N-(i+1);j++)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}

	for (i = 0; i < N; i++)
	{
		printf("%d\n", arr[i]);
	}

	getchar();
	return 0;
}