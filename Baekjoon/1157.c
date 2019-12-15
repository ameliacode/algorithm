#include<stdio.h>
#include<string.h>

int main()
{
	char str[1000000] = "";
	char alpha[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	int num[26];
	int max = 0,i,j;
	int max_ind, len;
	int flag = 0;	//max와 같은지 세어보자

	for (i = 0; i < 26; i++)
		num[i] = 0;

	scanf("%s", str);
	len = strlen(str);

	for (i = 0; i < len ; i++)
	{
		if ('A' <= str[i] && str[i] <= 'Z') 
			str[i] = str[i] + ('a' - 'A');
		for (j = 0; j < 26; j++)
		{
			if (alpha[j] == str[i])
			{
				num[j]++;
				break;
			}
		}
	}

	for (i = 0; i < 26; i++)
	{
		if (max < num[i])
		{
			max = num[i];
			max_ind = i;
		}
	}

	for (i = 0; i < 26; i++)
	{
		if (max == num[i]) flag++;
	}

	if (flag != 1) printf("?\n");
	else printf("%c\n", alpha[max_ind] - ('a'-'A'));

	return 0;
}
