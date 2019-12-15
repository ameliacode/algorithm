#include<stdio.h>
#include<string.h>

void recursive(int n)
{
	if (n < 10) {
		printf("%d\n", n);
	}
	else {
		printf("%d\n", n % 10);
		recursive(n / 10);
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	recursive(n);
	//return 0;
}
