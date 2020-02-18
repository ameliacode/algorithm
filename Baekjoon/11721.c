#include<stdio.h>
#include<string.h>

int main()
{
	int i, j, start, end;
	int length = 0;
	char str[100] = "";
	scanf("%d", &length);
	scanf("%s", str);

	start = 0;
	for (i = 0; i < strlen(str); i++)
	{
		printf("%c", str[i]);
		if ((i + 1) % 10 == 0)
			printf("\n");
	}
	return 0;
} 