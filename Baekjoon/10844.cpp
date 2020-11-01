#include<iostream>

using namespace std;

int main() {
	long long DP[101][10] = { };	//DP[i][j]: i째 자리, j: 끝자리가 j인 숫자 | 로 끝나는 숫자들의 수
	int N;

	cin >> N;
	
	for (int i = 1; i <= 9; i++) {
		DP[1][i] = 1;
	}
	DP[1][0] = 0;

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j == 0) {
				DP[i][0] = DP[i - 1][1] % 1000000000;
			}
			else if (j == 9) {
				DP[i][9] = DP[i - 1][8] % 1000000000;
			}
			else {
				DP[i][j] = (DP[i - 1][j - 1] + DP[i - 1][j + 1]) % 1000000000;
			}
		}
	}

	long long answer = 0;
	for (int i = 0; i < 10; i++) {
		answer += DP[N][i];
	}

	cout << answer % 1000000000 << endl;

	return 0;
}