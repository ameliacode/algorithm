#include<stdio.h>
#include<string.h>

void hanoi(int n, char start, char work, char target);
int main()
{
	int N;
	scanf("%d", &N);

	hanoi(N, 'A','B','C');
	return 0;
}

void hanoi(int n, char start, char work, char target) {
	if (n == 1)
		printf("%c %c\n", start, target);
	else {
		hanoi(n - 1, start, target, work);
		printf("%c %c\n", start, target);
		hanoi(n - 1, work, start, target);
	}
}
