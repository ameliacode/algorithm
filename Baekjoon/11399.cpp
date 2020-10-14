#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int N;
	int result = 0;
	vector<int> P;

	cin >> N;
	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		P.push_back(input);
	}

	sort(P.begin(),P.end());
	
	for (int i = 0; i < P.size(); i++) {
		for (int j = 0; j <= i; j++) {
			result += P[j];
		}
	}

	cout << result << endl;

	return 0;
}