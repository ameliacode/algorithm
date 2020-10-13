#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<deque>

using namespace std;

int main() {

	int test_case;

	cin >> test_case;

	for (int i = 0; i < test_case; i++) {
		int N, index, max = -1;
		deque<pair<int,int>> dq;
		cin >> N >> index;

		for (int j = 0; j < N; j++) {
			int input;
			cin >> input;
			dq.push_back(make_pair(input, j));
		}

		int count = 0;
		int current = dq[index].first;

		while (true) {
			int max = max_element(dq.begin(), dq.end())->first;

			if (max == current && index == dq.front().second) {
				count++;
				break;
			}
			if (max > dq.front().first) {
				dq.push_back(dq.front());
				dq.pop_front();
			}
			else if (max == dq.front().first) {
				dq.pop_front();
				count++;
			}
		}

		cout << count << endl;
	}

	return 0;
}