#include<stdio.h>

int main()
{
	int score[5];
	int i, total = 0;

	for (i = 0; i < 5; i++)
	{
		scanf("%d", &score[i]);
		if (score[i] < 40) score[i] = 40;
		total += score[i];
	}
	printf("%d", total / 5);

	return 0;
}