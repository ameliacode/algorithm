#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int modulo(int a, int b)
{
	return a%b;
}

int main()
{
	int a,b, result;
	scanf("%d %d", &a, &b);
	result=modulo(a,b);
	printf("%d\n", result);
	
	return 0;
}
