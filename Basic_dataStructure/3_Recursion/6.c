#include<stdio.h>
#include<string.h>

int gcd(int a, int b)
{
	if (a == 0 || b == 0) 
		return (a == 0) ? b : a;
	else{
		if (a > b) {
			gcd(a%b, b);
		}
		else gcd(a, b%a);
	}
}

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);

	printf("%d",gcd(a, b));

	return 0;
}
