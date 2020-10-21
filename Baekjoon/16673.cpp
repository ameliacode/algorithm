#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
	
	int C, K, P;

	cin >> C >> K >> P;

	int answer = 0;
	for (int i = 0; i <= C; i++) {
		answer += K * i + P * i * i;
	}

	cout << answer << endl;
	
	return 0;
}