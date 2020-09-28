#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
	if (a.first == b.first) {
		return a.second < b.second;
	}
	return a.first < b.first;
}

int main()
{
	int N;
	cin >> N;
	
	vector<pair<int, int>> point(N);

	for (int i = 0; i < N; i++) {
		cin >> point[i].first >> point[i].second;
	}

	stable_sort(point.begin(), point.end(),compare);

	for (int i = 0; i < N; i++)
	{
		cout << point[i].first << " " << point[i].second << "\n";
	}

	return 0;
}