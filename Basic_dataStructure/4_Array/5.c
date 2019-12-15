#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {
	int arr[100][100] = { 0, };
	int N, M, i, j;
	int num = 1;

	scanf("%d %d", &N, &M);


	if (N <= M) {

		for (i = 0; i < N; i++)
		{
			for (j = 0; j <= i; j++) {
				arr[j][i - j] = num;
				num++;
			}
		}
		if (N - M < 0) {
			for (i = N; i < M; i++) {
				for (j = 0; j < N; j++) {
					arr[j][i - j] = num++;
				}
			}
		}
		for (i = M; i < N + M - 1; i++) {
			for (j = M - 1; j >= 1 ; j--)
			{
				if (i - j < N) {
					arr[i - j][j] = num;
					num++;
				}
			}
		}
	}
	else {
		for (i = 0; i < M; i++)
		{
			for (j = 0; j <= i; j++) {
				arr[j][i - j] = num;
				num++;
			}
		}
		if (N - M > 0) {
			for (i = M; i < N; i++) {
				for (j = M-1; j >= 0; j--) {
					arr[i-j][j] = num++;
				}
			}
		}
		for (i = N; i < N + M - 1; i++) {
			for (j = M - 1; j >= 1; j--)
			{
				if (i - j < N) {
					arr[i - j][j] = num;
					num++;
				}
			}
		}

	}
	

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			printf(" %2d", arr[i][j]);
		}
		printf("\n");
	}

	return 0;
}
