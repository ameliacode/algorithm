#include<stdio.h>
#include<stdlib.h>

int main()
{
	int N;
	int *score;
	int i,max = 0;
	double *score2;
	double mean=0;

	scanf("%d", &N);
	score = (int*)malloc(N * sizeof(int));
	score2 = (double*)malloc(N * sizeof(double));

	for (i = 0; i < N; i++)
	{
		scanf("%d", &score[i]);
		if (max < score[i]) max = score[i];
	}
	for (i = 0; i < N; i++)
	{
		score2[i] = (double)score[i] / max * 100;
		mean += score2[i];
	}
	printf("%f\n", mean / N);

	return 0;
}
