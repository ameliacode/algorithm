#include<stdio.h>
//에라토스테네스의 체
int main()
{
	int N, i, j;
	int flag = 1, cnt = 0;
	int *check;
	N = 1;

	check = (int*)malloc(sizeof(int)*246913);

	for (i = 2; i <= 246913; i++) check[i] = 1;

	for (i = 2; i*i < 246913; i++)
	{
		if (check[i] == 1)
		{
			for (j = i; i*j <= 246913; j++)
			{
				check[i*j] = 0;
			}
		}
	}

	while (N!=0)
	{
		scanf("%d", &N);
		
		for (i = N + 1; i <= 2 * N; i++)
		{
			if (check[i] == 1) cnt++;
		}
		if (N == 0) break;
		printf("%d\n", cnt);
		cnt = 0;
	}

	return 0;
}