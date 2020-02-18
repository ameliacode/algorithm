#include<stdio.h>

int main()
{
	int apt[15][15];
	int i, j, k;
	int T, m, n;

	for (i = 0; i < 15; i++) apt[0][i] = i;

	for (i = 1; i < 15; i++)
	{
		for (j = 0; j < 15; j++)
		{
			apt[i][j] = 0;
			for (k = 0; k <= j; k++)
			{
				apt[i][j] += apt[i - 1][k];
			}
		}
	}

	scanf("%d", &T);

	for (i = 0; i < T; i++)
	{
		scanf("%d %d", &m, &n);
		printf("%d\n", apt[m][n]);
	}


	return 0;
}