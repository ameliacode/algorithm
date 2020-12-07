#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int Power(int N, int Z) {
	int i;
	int total = 1;

	for (i = 0;i < N; i++) 
	{
		total = total * Z;
		//printf("%d\n", total);
	}
	return total;
}

int convert(char str) {
	return str - 'a';
}

int main() {

	int N, i, j ,Z;
	char input[1000][11];
	int total = 0;
	int length;

	scanf("%d %d", &N, &Z);

	for (i = 0;i < N;i++) {
		scanf("%s", input[i]);

		length = strlen(input[i]);
		for (j = 0;j < length;j++) 
		{
			total = total + convert(input[i][j])*Power(j,Z);
		}
		printf("%d\n", total);
		total = 0;
	}


	return 0;
}