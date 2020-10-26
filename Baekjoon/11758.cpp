#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

int main() {
	pair<int, int> P1;
	pair<int, int> P2;
	pair<int, int> P3;

	int result = 0;

	cin >> P1.first >> P1.second;
	cin >> P2.first >> P2.second;
	cin >> P3.first >> P3.second;

	int CCW = P1.first * P2.second + P2.first * P3.second + P3.first * P1.second;
	CCW += - P1.second * P2.first - P2.second * P3.first - P3.second * P1.first;

	if (CCW > 0) {
		cout << 1 << endl;
	}
	else if (CCW < 0) {
		cout << -1 << endl;
	}
	else {
		cout << 0 << endl;
	}
	
	return 0;
}