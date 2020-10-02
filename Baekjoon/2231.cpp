#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstdio>

using namespace std;

int func(int N) {
	int result = N;
	while (N > 0) {
		result += N % 10;
		N = N / 10;
	}
	return result;
}

int main()
{
	int N;

	cin >> N;
	int result;

	for (int i = 1; i <=1000000; i++) {
		if (func(i) == N) {
			result = i;
			break;
		}
		result = 0;
	}	

	cout << result << endl;
	
	return 0;
}