#include<iostream>
#include<queue>
#include<vector>
#include<cstdio>

using namespace std;

int gcd(int a, int b) {
	int num;

	while (b != 0) {
		num = a % b;
		a = b;
		b = num;
	}
	return a;
}

int main()
{
	int N, denom;
	int numer[101];

	cin >> N;

	cin >> denom;
	for (int i = 0; i < N - 1; i++) {
		cin >> numer[i];
	}

	for (int i = 0; i < N - 1; i++) {
		cout << denom / gcd(denom, numer[i]) << "\/" << numer[i] / gcd(denom, numer[i]) << endl;
	}

	return 0;
}