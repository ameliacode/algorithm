#include<stdio.h>
#include<string.h>

int mostOnes(int A[][100], int n)
{
	int i, j, row = 0, jmax = 0;
	for (i = 0; i < n; i++)
	{
		j = 0;
		while ((j < n) && (A[i][j] == 1)){
			j += 1;
			if (j > jmax){
				row = i;
				jmax = j;
			}
		}
	}
	return row;
}

int main()
{
	int i, j, n, result;
	int arr[100][100];
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	result = mostOnes(arr, n);
	printf("%d\n", result);
	return 0;
}
