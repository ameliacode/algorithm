#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

int main()
{
	//Counting sort
	int N;
	int num;
	int arr[10001] = { 0 };

	scanf("%d", &N); //시간 초과 문제 해결

	for (int i = 0; i < N; i++) {
		int cnt = 0;
		scanf("%d", &cnt);
		arr[cnt]++;
	}

	for (int i = 1; i < 10001; i++) {
		for (int j = 0; j < arr[i]; j++)
			printf("%d\n", i);
	}

	return 0;
}
