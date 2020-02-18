#include<stdio.h>

int d(int num)
{
	return num + (num / 1000) + (num % 1000) / 100 + (num % 100) / 10 + (num % 10);
}

int main()
{
	int i, temp;
	int isSelf[10000];
	for (i = 0; i < 10000; i++) isSelf[i] = 0;
	
	for (i = 1; i <= 10000; i++)
	{
		temp = i;
		while (temp <= 10000)
		{
			temp = d(temp);
			if(temp<=10000) isSelf[temp - 1] = 1;
		}
	}

	for (i = 0; i < 10000; i++)
	{
		if (isSelf[i] == 0) printf("%d\n", i + 1);
	}
	return 0;
}