#include<stdio.h>
#include<string.h>

int main() {
	int N, i, j, num;
	
	scanf("%d", &N);
	int **arr = (int**)malloc(N * sizeof(int*));
	for (i = 0; i < N; i++) {
		arr[i] = (int*)malloc(N * sizeof(int));
	}

	num = 1;
	for (i = 0; i < N; i++)
	{
		if (i % 2 == 0) {
			for (j = 0; j < N; j++){
				arr[i][j] = num;
				num++;		
			}
		}
		else {
			for (j = N - 1; j >= 0; j--) {
				arr[i][j] = num;
				num++;
			}
		}
	}

	for (i = 0; i < N; i++){
		for (j = 0; j < N; j++) {
			printf(" %d", arr[i][j]);
		}
		printf("\n");
	}


	return 0;
}
