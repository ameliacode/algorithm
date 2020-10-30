#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<deque>

using namespace std;
int total = 0;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		deque<long long> dq{ 1,1,1,2,2 };
		int N;

		cin >> N;

		if (N >= 6) {
			for (int j = 5; j < N; j++) {
				long long input = dq.front() + dq.back();
				dq.push_back(input);
				dq.pop_front();
				
			}	
			cout << dq.back() << endl;
		}
		else {	//배열로 접근하면 물론 인덱스로 바로 접근하면 된다.
			// 좀 돌아가서 생각한 편..
			switch (N) {
			case 1: case 2: case 3:
				cout << 1 << endl;
				break;
			case 4: case 5:
				cout << 2 << endl;
				break;
			default:
				break;
			}
		}
		
	}

	return 0;
}