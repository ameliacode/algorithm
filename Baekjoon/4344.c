#include<stdio.h>
#include<stdlib.h>

int main()
{
	int C,N;
	int i, j;
	int *score;
	int top = 0;
	double mean = 0;

	scanf("%d", &C);
	for (i = 0; i < C; i++)
	{
		scanf("%d", &N);
		score = (int*)malloc(N * sizeof(int));
		for (j = 0; j < N; j++)
		{
			scanf("%d", &score[j]);
			mean += (double)score[j];
		}
		mean = (double) mean/ N;
		for (j = 0; j < N; j++)
		{
			if (mean < score[j]) ++top;
		}
		printf("%.3f%%\n", (double)top / N * 100);
		free(score);
		mean = 0;
		top = 0;
	}
	return 0;
}