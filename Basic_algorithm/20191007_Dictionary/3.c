#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int *A;
int n;

int findElement(int l, int r, char str[]) {
	int i;
	int K = 0, M;
	for (i = 0; i < strlen(str) + 1; i++) {
		if (l == r) {
			K = l;
		}
		M = (l + r) / 2;
		//printf("%d\n", M);
		if (str[i] == 'N') {
			r = M;
		}
		else if(str[i]=='Y'){
			l = M + 1;
		}
	}
	return K;
}

int main() {

	int A, B, N, i;
	char *str;

	scanf("%d %d %d", &A, &B, &N);
	getchar();
	str = (char*)malloc(sizeof(char)*(N + 1));
	scanf("%s", str);

	printf(" %d", findElement(A, B, str));

	return 0;
}