#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

void fibonacci(int n) {
	long long result[91];
	result[0] = 0;
	result[1] = 1;

	for (int i = 0; i < n; i++) {
		result[i + 2] = result[i + 1] + result[i];
	}
	cout << result[n - 1] << " " << result[n] << endl;
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int N;
		cin >> N;

		if (N == 0) {
			cout << "1 0" << endl;
		}
		else if (N == 1) {
			cout << "0 1" << endl;
		}
		else {
			fibonacci(N);
		}
	}
	
	return 0;
}