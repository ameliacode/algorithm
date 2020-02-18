#include<stdio.h>

int main()
{
	int T, H, W, N;
	int i, j, save;
	int room;

	scanf("%d", &T);
	for (i = 0; i < T; i++)
	{
		scanf("%d %d %d", &H, &W, &N);
		j = 1;
		while (1)
		{
			if (1 + (H - 1)*(j-1) <= N && N <= H * j) {
				save = j; 
				room = N - (j - 1)*H;
				break;
			}
			else j++;
		}
		printf("%d%02d\n",room, save);
	}


	return 0;
}