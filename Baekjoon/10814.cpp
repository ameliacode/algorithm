#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

bool compare(pair<int, string> a, pair<int, string> b)
{
	return a.first < b.first;
}

int main()
{
	int N;
	cin >> N;
	
	vector<pair<int, string>> member(N);

	for (int i = 0; i < N; i++) {
		cin >> member[i].first >> member[i].second;
	}

	stable_sort(member.begin(), member.end(),compare);

	for (int i = 0; i < N; i++)
	{
		cout << member[i].first << " " << member[i].second << "\n";
	}

	return 0;
}