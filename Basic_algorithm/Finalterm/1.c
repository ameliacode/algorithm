#include<stdio.h>
#include<stdlib.h>

int Combination(int n, int k) {
	int result, i, j;
	int arr[31][31];

	for(i=0;i<31;i++){
		for(j=0;j<31;j++){
			arr[i][j]=1;
		}
	}

	for (i = 2; i < 31; i++) 
	{
		for (j = 1; j < i; j++) 
		{
			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j ];
			//printf("%d",arr[i][j]);
		}
		//printf("\n");
	 }
	
	result = arr[n][k];

	return result;
}

int main() {
	int N, K;
	int result;

	scanf("%d %d", &N, &K);

	result=Combination(N,K);
	printf("%d\n",result);


	return 0;
}