#include<iostream>
#include<cstdio>
#include<string>
#include<deque>
#include<vector>

using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int N, M;
	vector<int> card;
	int answer = 0;
	int min = 999999;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		card.push_back(input);
	}

	for (int i = 0; i < N - 2; i++) {
		for (int j = i + 1; j < N - 1; j++) {
			for (int k = j + 1; k < N; k++) {
				int total = card[i] + card[j] + card[k];
				if (0 <= M - total && M - total < min) {
					min = M - total;
					answer = total;
				}
			}
		}
	}
	cout << answer << endl;

	return 0;
}