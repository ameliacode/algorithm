#include<stdio.h>
#include<string.h>

int add(int n)
{
	if (n == 1) return 1;
	else return add(n - 1) + n;
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("%d", add(n));
	//return 0;
}
