#include<stdio.h>
#include<string.h>

int main()
{
	int N, X, i, j, ind = 0, cnt;
	int arr[100];
	int tmp;
	int a[100];
	int b[100];
	scanf("%d", &N);

	for (i = 0; i < N; i++){
		scanf("%d", &arr[i]);
	}

	scanf("%d", &X);

	for (i = 0; i < X; i++)
	{
		scanf("%d %d", &a[i], &b[i]);
	}
	
	while (X!=0)
	{
		for (i = a[ind], j = b[ind], cnt = 0; cnt < (b[ind] - a[ind] + 1) / 2; i++, j--, cnt++) {
			tmp = arr[j];
			arr[j] = arr[i];
			arr[i] = tmp;
			//printf("%d %d %d\n", tmp, arr[i], arr[j]);
		}
		--X;
		++ind;
	}

	for (i = 0; i < N; i++)
	{
		printf(" %d", arr[i]);
	}
	
	return 0;
}
