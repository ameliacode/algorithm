#include<stdio.h>
#include<string.h>

int main()
{
	int input[3];
	int i, j;
	int min = 101, max = 0, result;
	int min_ind, max_ind;

	for (i = 0; i < 3; i++)
	{
		scanf("%d", &input[i]);
		if (input[i] < min)
		{
			min = input[i];
			min_ind = i;
		}
		if (max < input[i])
		{
			max = input[i];
			max_ind = i;
		}
	}

	for (i = 0; i < 3; i++)
	{
		if (min_ind != i && max_ind != i) {
			printf("%d\n", input[i]);
			break;
		}
	}

	return 0;
}