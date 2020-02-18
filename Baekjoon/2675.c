#include<stdio.h>
#include<string.h>

int main()
{
	int T, i, j, k, R;
	char str[9] = "";

	scanf("%d", &T);

	for (k = 0; k < T; k++)
	{
		scanf("%d", &R);
		scanf("%s", str);
		for (i = 0; i < strlen(str); i++)
		{
			for (j = 0; j < R; j++)
			{
				printf("%c",str[i]);
			}
		}
		printf("\n");
	}

	return 0;
}