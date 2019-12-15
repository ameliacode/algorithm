#include<stdio.h>
#include<string.h>

int main()
{
	int X, i, j, num = 0;
	int a = 1, b = 1;
	int cnt = 0;

	scanf("%d", &X);

	for (i = 2;; i++)
	{
		if (i % 2 != 0)
		{
			for (j = 1;j< i; j++)
			{
				cnt++;
				a = j;
				b = abs(i - a);
				//printf("%d %d %d %d\n", a, b, cnt, i);
				if (cnt == X) break;	
			}
		}
		else {
			for (j = i - 1; j>=1; j--)
			{
				cnt++;
				a = j;
				b = abs(i - a);
				//printf("%d %d %d %d\n", a, b, cnt, i);
				if (cnt == X) break;
			}
		}
		if (cnt == X) break;
	}
		
	printf("%d/%d\n", a, b);


	
	return 0;
}
