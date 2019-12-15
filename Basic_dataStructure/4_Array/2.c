#include<stdio.h>
#include<string.h>

int main()
{
	int N, i, len, tmp, ind, ind2;
	int X[100];
	int len2[100];
	
	scanf("%d", &N);
	for (i = 0; i < N; i++){
		scanf("%d", &X[i]);
	}

	scanf("%d", &len);
	for (i = 0; i < len; i++){
		scanf("%d", &len2[i]);
	}

	tmp = X[len2[0]];
	while (len - 1) {
		len--;
		ind = len2[len];
		ind2 = len2[len - 1];
		X[ind] = X[ind2];
		/*for (i = 0; i < N; i++) {
			printf(" %d", X[i]);
		}*/
		//printf("\n");
	}
	X[len2[1]] = tmp;

	for (i = 0; i < N; i++) {
		printf(" %d", X[i]);
	}

	return 0;
}
