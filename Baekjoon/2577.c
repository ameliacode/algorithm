#include<stdio.h>
#include<string.h>

int main()
{
	int num[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int cnt[10] = { 0,0,0,0,0,0,0,0,0,0 };
	int a, b, c;
	int i, j, total, temp;

	scanf("%d %d %d", &a, &b, &c);

	total = a * b*c;

	while (total != 0)
	{
		temp = total % 10;
		for (i = 0; i < 10; i++)
		{
			if (temp == num[i]) ++cnt[i];
		}
		total = total / 10;
	}

	for (i = 0; i < 10; i++)
	{
		printf("%d\n", cnt[i]);
	}

	return 0;
}
