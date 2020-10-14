#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>
#include<algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	else return a.second < b.second;
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int N;
	vector<pair<int, int>> v;

	cin >> N;
	
	for (int i = 0; i < N; i++) {
		int start, end;
		cin >> start >> end;
		v.push_back(make_pair(start, end));
	}

	sort(v.begin(), v.end(), compare);

	int end_time = v[0].second;
	int answer = 0;
	for (int i = 1; i < N; i++) {
		if (end_time <= v[i].first) {
			++answer;
			end_time = v[i].second;
		}
	}
	
	cout << answer + 1 << endl;

	return 0;
}