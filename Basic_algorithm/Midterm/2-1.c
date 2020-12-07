#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int main() {

	int N, i, j;
	char input[1000][11];
	int total = 0;
	int length;

	scanf("%d", &N);

	for (i = 0;i < N;i++) {
		scanf("%s", input[i]);

		length = strlen(input[i]);
		for (j = 0;j < length;j++) {
			total = total + (input[i][j]);
		}
		printf("%d\n", total);
		total = 0;
	}


	return 0;
}