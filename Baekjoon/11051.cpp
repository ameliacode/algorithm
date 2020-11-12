#include <string>
#include <vector>
#include <iostream>

using namespace std;

//재귀함수 사용 -> 시간 초과
//이항계수 알고리즘 사용 (n,k) = (n-1,k) + (n-1,k-1)

int main()
{
	int n, m;

	cin >> n >> m;

	int DP[1001][1001];

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (i == j || j == 0) DP[i][j] = 1;
			else if (j == 1 || j == i - 1) DP[i][j] = i;
			else DP[i][j] = (DP[i - 1][j] + DP[i - 1][j - 1]) % 10007;
		}
	}

	cout << DP[n][m] << endl;

	return 0;
}