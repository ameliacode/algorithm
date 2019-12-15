#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {
	int N, M, L, k;
	int i, j;
	int C[100][100];
	int cnt = 1;
	int num = 1;
	int row_a = 0;
	int row_b;

	scanf("%d %d", &N, &M);
	row_b = N - 1;

	for (cnt = 0; cnt < N; cnt++) {
		if (cnt % 2 == 0) {
			for (j = 0; j < M; j++) {
				C[row_a][j] = num;
				num++;
			}
			row_a++;
		}
		else {
			for (j = M - 1; j >= 0; j--) {
				C[row_b][j] = num;
				num++;
			}
			row_b--;
		}
	}

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			printf(" %d", C[i][j]);
		}
		printf("\n");
	}

	return 0;
}
