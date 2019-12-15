#include<stdio.h>

//애라토스테네스의 체
int main()
{
	int M, N, i, j;
	int flag = 1; //1.Yes 0.No
	int total = 0, min = 10000;

	scanf("%d %d", &M, &N);

	int *check = (int*)malloc(sizeof(int)*(N+1));

	for (i = 2; i <= N; ++i) check[i] = 1; //check초기화
	

	for (i = 2; i*i<=N; ++i)
	{
		if (check[i] == 1) {
			for (j = i; j*i <= N; ++j) //i의 배수를 거른다.
			{
				check[i*j] = 0; //그에 해당하는 check 인덱스도 check해주기
			}
		}
	}

	for (i = M; i <= N; ++i)
	{
		if (check[i] == 1) printf("%d\n", i);
	}

	return 0;
}
