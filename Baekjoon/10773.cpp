#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<stack>

using namespace std;

int main()
{
	int K;
	stack<int> v;
	int total = 0;

	cin >> K;

	for (int i = 0; i < K; i++) {
		int input;
		cin >> input;

		if (input == 0) {
			v.pop();
		}
		else {
			v.push(input);
		}
	}

	if (!v.empty()) {	
		while (!v.empty()) {
			total += v.top();
			v.pop();
		}		
	}

	cout << total << endl;

	return 0;
}