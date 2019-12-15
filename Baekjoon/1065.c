#include<stdio.h>

int isHansu(int num)
{
	int a = num / 100;
	int b = (num % 100) / 10;
	int c = num % 10;
	if (2*b==a+c) return 1;
	else return 2;
}

int main()
{
	int i;
	int N, count = 0;
	scanf("%d", &N);
	if (N < 100) printf("%d\n", N);
	else {
		for (i = 100; i <= N; i++)
		{
			if (isHansu(i) == 1) count++;
		}
		printf("%d\n", 99 + count);
	}
	
	return 0;
}
