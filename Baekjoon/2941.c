#include<stdio.h>
#include<string.h>

int main()
{
	int cnt = 0, len;
	int i, j, k;
	char input[101] = "";

	scanf("%s", input);
	len = strlen(input);

	for (i = 0; i < len; i++)
	{
		if (input[i] == 'c')
		{
			if (input[i+1] == '=' || input[i+1]=='-')
			{
				++i;
			}
			++cnt;
		}
		else if (input[i] == 'd')
		{
			if ((input[i + 1] == 'z' && input[i+2]=='='))
			{
				i += 2;
			}
			else if (input[i + 1] == '-')
			{
				++i;
			}
			++cnt;
		}
		else if (input[i] == 'l')
		{
			if (input[i + 1] == 'j')
			{
				++i;
			}
			++cnt;
		}
		else if (input[i] == 'n')
		{
			if (input[i + 1] == 'j')
			{
				++i;
			}
			++cnt;
		}
		else if (input[i] == 's')
		{
			if (input[i + 1] == '=')
			{
				++i;
			}
			++cnt;
		}
		else if (input[i] == 'z')
		{
			if (input[i + 1] == '=')
			{
				++i;
			}
			++cnt;
		}
		else ++cnt;
	}

	printf("%d\n", cnt);

	return 0;
}