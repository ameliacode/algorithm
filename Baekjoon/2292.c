#include<stdio.h>

int main()
{
	int i = 0;
	int N, total = 1;
	scanf("%d",&N);

	while (1)
	{
		total +=  6 * i;
		//printf("%d\n",total);
		if (total >= N) break;
		i++;	
	}
	printf("%d\n", i+1);


	return 0;
}
