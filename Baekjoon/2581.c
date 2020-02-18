#include<stdio.h>

int main()
{
	int M,N, i, j;
	int flag = 1; //1.Yes 0.No
	int total = 0, min = 10000;

	scanf("%d %d",&M, &N);

	for (i = M; i <= N; i++)
	{
		if (i != 1) {
			for (j = 2; j < i; j++)
			{
				if (i%j == 0)
				{
					flag = 0;
					break;
				}
			}
			if (flag == 1) {
				total += i;
				if (i < min) min = i;
			}
			else flag = 1;
		}
	}

	if (total == 0)
		printf("-1");
	else {
		printf("%d\n%d\n", total, min);
	}


	return 0;
}
