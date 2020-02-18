#include<stdio.h>
#include<string.h>

int main()
{
	char str[101] = "";
	char alpha[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	int num[26];
	int i, j;

	for (i = 0; i < 26; i++)
	{
		num[i] = -1;
	}

	scanf("%s", str);

	for (i = 0; i < strlen(str); i++)
	{
		for (j = 0; j < 26; j++)
		{
			if (alpha[j] == str[i])
			{
				if (num[j] == -1)
				{
					num[j] = i;
				}
				else continue;
			}
		}
	}

	for (i = 0; i < 26; i++)
	{
		printf("%d ", num[i]);
	}

	return 0;
}