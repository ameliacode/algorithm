#include<stdio.h>

int main() {
	int cycle = 0;
	int N = 0;
	int hub = 0;
	int total = 0;

	scanf("%d", &N);
	total = N;
	while (1)
	{
		hub = (total / 10) + (total % 10);
		total = (total % 10) * 10 + (hub%10);
		++cycle;
		if (total == N) break;
	}
	printf("%d\n", cycle);
	return 0;
}
