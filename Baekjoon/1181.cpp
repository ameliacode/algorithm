#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

int main() {

	int N;
	vector < pair<int, string>> v;
	string str;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> str;
		v.push_back(pair<int, string>(str.size(), str));
	}

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	for (int i = 0; i < v.size(); i++) {
		cout << v[i].second << endl;
	}

	return 0;
}