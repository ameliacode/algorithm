#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int N, K;
	int answer = 0;
	vector<int> money;
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		money.push_back(input);
	}

	for (int i = N - 1; i >= 0; i--) {
		if (money[i] <= K) {
			while (K - money[i] >= 0) {
				K = K - money[i];
				//cout << K << endl;
				answer++;
			}
		}
	}

	cout << answer << endl;

	return 0;
}