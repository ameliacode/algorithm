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

	int N;
	int stairs[301];
	int maximum[301];
	
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> stairs[i];
	}

	maximum[1] = stairs[1];
	maximum[2] = stairs[1] + stairs[2];
	maximum[3] = max(stairs[1] + stairs[3], stairs[2]+stairs[3]);
	
	for (int i = 4; i <= N; i++) {
		maximum[i] = max(maximum[i - 2] + stairs[i], maximum[i - 3] + stairs[i - 1] + stairs[i]);
	}

	cout << maximum[N] << endl;

	return 0;
}