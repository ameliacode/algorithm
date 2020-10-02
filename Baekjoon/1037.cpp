#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstdio>

using namespace std;

int main()
{
	int N;

	cin >> N;

	int* div = new int[N];

	for (int i = 0; i < N; i++) {
		cin >> div[i];
	}

	sort(div, div+N);

	cout << div[0] * div[N - 1];	

	return 0;
}