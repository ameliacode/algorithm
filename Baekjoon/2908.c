#include<stdio.h>
#include<string.h>

int main()
{
	int A, B, a, b;

	scanf("%d %d", &a, &b);

	A = (a % 10) * 100 + (a % 100 / 10) * 10 + (a / 100);
	B = (b % 10) * 100 + (b % 100 / 10) * 10 + (b / 100);

	if (A > B) printf("%d\n", A);
	else printf("%d\n", B);


	return 0;
}