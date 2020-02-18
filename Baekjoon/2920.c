#include<stdio.h>

int main()
{
	int flag, i;
	int input[8];

	for (i = 0; i < 8; i++)
	{
		scanf("%d", &input[i]);
	}

	if (input[0] == 1)
	{
		for (i = 0; i < 7; i++)
		{
			if (input[i] + 1 != input[i + 1]) {
				flag = 0;
				break;
			}
			flag = 1;
		}
	}
	else if (input[0] == 8)
	{
		for (i = 0; i < 7; i++)
		{
			if (input[i] - 1 != input[i + 1]) {
				flag = 0;
				break;
			}
			flag = 2;
		}
	}
	else flag = 0;

	if (flag == 0) printf("mixed\n");
	if (flag == 1) printf("ascending\n");
	if (flag == 2) printf("descending\n");
	
	return 0;
}