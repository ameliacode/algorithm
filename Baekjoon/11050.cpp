#include<iostream>
#include<queue>
#include<vector>
#include<cstdio>

using namespace std;

int factorial(int N) {
	int result = 1;
	for (int i = 1; i <= N; i++) {
		result *= i;
	}
	return result;
}

int main()
{
	int N,K;

	cin >> N >> K;

	cout << factorial(N) / (factorial(K) * factorial(N - K));

	return 0;
}