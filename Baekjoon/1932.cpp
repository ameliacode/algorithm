#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>
#include<algorithm>

using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int triangle[501][501];

	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> triangle[i][j];
		}
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) triangle[i][j] += triangle[i - 1][j];
			else if (j == i) triangle[i][j] += triangle[i - 1][j - 1];
			else triangle[i][j] += max(triangle[i - 1][j - 1] , triangle[i - 1][j]);
		}
	}

	int answer = 0;
	for (int i = 0; i < n; i++) {
		answer = max(answer, triangle[n - 1][i]);
	}

	cout << answer << endl;

	return 0;
}