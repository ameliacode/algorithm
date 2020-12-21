#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//구글 찬스.. 시작점이 증가하고 끝점이 증가하면 겹치는 부분이 없다에서 출발해야 함

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);

	vector<pair<int, int>> lines;
	
	int N;
	int dp[100];

	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		lines.push_back(make_pair(a, b));
	}
	
	sort(lines.begin(), lines.end()); //오름차순 정렬

	dp[0] = 1;

	for (int i = 1; i < N; i++)
	{
		int m = 0;
		for (int j = 0; j < i; j++)
		{
			if (lines[i].second > lines[j].second) //겹치는 선이 존재하면
			{
				m = max(m, dp[j]);
			}
		}
		dp[i] = m + 1;
	}

	int m = 0;
	for (int i = 0; i < N; i++) {
		m = max(dp[i], m);
	}
	cout << N - m << endl;

	return 0;
}