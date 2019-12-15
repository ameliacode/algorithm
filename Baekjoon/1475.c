#include<stdio.h>
#include<string.h>
#include<math.h>

int main()
{
	char set[7]="";
	char num[10] = { '0','1','2','3','4','5','6','7','8','9' };
	int check[10];
	double max;
	int a = 0, b = 0, i, j, k;
	scanf("%s", set);

	for (i = 0; i < 10; i++) check[i] = 0;

	for (j = 0; j < 10; j++)
	{
		for (i = 0; i < strlen(set); i++)
		{
			if (num[j] == set[i])
				check[(num[j]-'0')]++;
		}
	}

	for (i = 0; i < 10; i++)
	{
		//printf("%d\n", check[i]);
		if (a < check[i]&&i!=6&&i!=9) a = check[i];
	}
	b = check[6] + check[9];
	if (b % 2 != 0) b++;

	max = fmax((double)a, (double)(b/2));
	printf("%.f\n", max);

	return 0;
}
