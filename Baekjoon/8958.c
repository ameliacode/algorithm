#include<stdio.h>
#include<string.h>

int main()
{
	int C, i, j,Ocnt = 0, total = 0;
	char quiz[81] = "";

	scanf("%d", &C);

	for (i = 0; i < C; i++)
	{
		scanf("%s", quiz);
		for (j = 0; j < strlen(quiz); j++)
		{
			if (quiz[j] == 'O') Ocnt++;
			else Ocnt = 0;
			total += Ocnt;
		}
		printf("%d\n", total);
		total = 0;
		Ocnt = 0;
	}

	return 0;
}