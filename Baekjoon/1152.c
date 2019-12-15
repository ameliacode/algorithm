#include<stdio.h>

int main()
{
	char str[1000000] = "";
	int i, count = 0;
	int isSpace = 1;
	gets(str);
	for (i = 0; str[i]; i++)
	{
		if (str[i] == ' ') {
			isSpace =1;
		}
		else if (isSpace) {
			isSpace = 0;
			count++;
		}
	}
	printf("%d\n", count);

	return 0;
}
