#include<stdio.h>
#include<string.h>

int main()
{
	int N, M, i, j;
	int startRow, startCol, endRow, endCol, num;
	int arr[100][100];
	
	scanf("%d %d", &N, &M);
	startRow = 0; endRow = M - 1;
	startCol = 0; endCol = N - 1;

	num = 1;
	while (1) {
		for (j = startRow; j <= endRow; j++) {	//오른쪽으로
			arr[startCol][j] = num;
			num++;
		}
		if (num > N * M) break;
		startCol++;
		for (i = startCol; i <= endCol; i++) {	//아래로
			arr[i][endRow] = num;
			num++;
		}
		if (num > N * M) break;
		endRow--;
		for (j = endRow; j >= startRow;j--) {	//왼쪽으로
			arr[endCol][j] = num;
			num++;
		}
		if (num > N * M) break;
		endCol--;
		for (i = endCol; i >= startCol; i--) {	//위로
			arr[i][startRow] = num;
			num++;
		}
		if (num > N * M) break;
		startRow++;
	}
	
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			printf(" %d", arr[i][j]);
		}
		printf("\n");
	}

	return 0;
}
