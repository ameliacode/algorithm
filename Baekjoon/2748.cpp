#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	long long result[91];
	int n;

	cin >> n;
	
	result[0] = 0;
	result[1] = 1;
	for (int i = 0; i < n; ++i) {
		result[i + 2] = result[i + 1] + result[i];
	}

	cout << result[n] << endl;
	
	
	return 0;
}