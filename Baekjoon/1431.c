#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int sum(string serial) {
	int result = 0;
	for (int i = 0; i < serial.size(); i++) {
		if ('0' <= serial[i] && serial[i] <= '9') {
			result += serial[i] - '0';
		}
	}
	return result;
}

bool cmp(string a, string b) {
	if (a.size() != b.size()) {			//1번
		return a.size() < b.size();
	}
	else {
		int aSum = sum(a);
		int bSum = sum(b);
		if (aSum != bSum) 
			return aSum < bSum;			//2번
		else 
			return a < b;				//3반
	}
}

int main() {

	int N;
	cin >> N;
	vector<string> v(N);

	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end(), cmp);


	for (int i = 0; i < N; i++) {
		cout << v[i] << endl;
	}

}
