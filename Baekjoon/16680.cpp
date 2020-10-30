#include<iostream>

using namespace std;

int main() {

	cin.tie(0);
	cin.sync_with_stdio(0);

	int T;
	cin >> T;

	// 각 자리의 수가 홀수가 되어야 한다 -> N의 배수 * 10^9 - N
	// 아이디어 발상 싸움..

	for (int i = 0; i < T; i++) {
		long long num;
		cin >> num;

		cout << num * ((int)1e9 - 1) << endl;
	}
	
}