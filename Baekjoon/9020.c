#include<stdio.h>

int main()
{
	int T, i, j, k, half;
	int *arr;
	int check[10001];

	scanf("%d", &T);

	arr = (int*)malloc(sizeof(int) * T);

	for (i = 2; i <= 10000; i++)
		check[i] = 1;
	check[0] = 0;
	check[1] = 0;

	for (i = 2; i <= 10000; i++)
	{
		if (check[i] == 1)
		{
			for (j = i; j*i <= 10000; j++)
			{
				check[i*j] = 0;
			}
		}
	}

	for (i = 0; i < T; i++)
	{
		scanf("%d", &arr[i]);
		half = arr[i] / 2;
		for (j = half, k = half; j <= arr[i], k >= 2; j++, k--)
		{
			if (check[j] == 1 && check[k] == 1)
			{
				printf("%d %d\n", k, j);
				break;
			}
		}
	}
		
	getchar();

	return 0;
}