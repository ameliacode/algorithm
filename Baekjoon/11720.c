#include<stdio.h>
#include<string.h>

int main()
{
	int N, i, total=0;
	char input[101] = "";
	scanf("%d", &N);
	scanf("%s", input);

	for (i = 0; i < N; i++)
	{
		total += (input[i] - '0');
	}

	printf("%d\n", total);
	return 0;
}