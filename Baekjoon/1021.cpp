#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<deque>
#include<vector>

using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int N, M;
	int count = 0;
	deque<int> dq;
	vector<int> indexes;

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		dq.push_back(i);
	}

	for (int i = 0; i < M; i++) {
		int input;
		cin >> input;
		indexes.push_back(input);
	}

	int idx = 0;
	while (M > 0) {
		//cout << dq.front() << endl;
		if (dq.front() == indexes[idx]) {
			dq.pop_front();
			M--;
			idx++;
		}
		else {
			int next_idx = 0;
			for (int i = 0; i < dq.size(); i++) {
				if (indexes[idx] == dq[i]) {
					next_idx = i;
					break;
				}
			}

			if (next_idx < dq.size() - next_idx) {
				dq.push_back(dq.front());
				dq.pop_front();
				count++;
			}
			else {
				dq.push_front(dq.back());
				dq.pop_back();
				count++;
			}
		}
	}

	cout << count << endl;

	return 0;
}