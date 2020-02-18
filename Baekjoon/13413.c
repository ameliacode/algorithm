#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100001

int Min(int x, int y)
{
	if (x < y) return x;
	else return y;
}

int main() {

	int T, i, j, len;
	char input[MAX];
	char goal[MAX];
	int wcnt = 0, bcnt = 0;
	int total = 0;

	scanf("%d", &T);
	for (i = 0; i < T; i++)
	{
		scanf("%d", &len);
		scanf("%s", input);
		scanf("%s", goal);
		
		wcnt = 0;
		bcnt = 0;
		total = 0;
		for (j = 0; j < len; j++)
		{
			if (input[j] != goal[j])
			{
				if (input[j] == 'W') wcnt++;
				else bcnt++;

			}
		}
		total = Min(wcnt, bcnt) + abs(bcnt-wcnt);
		printf("%d\n", total);		

	}

	getchar();
	return 0;

}