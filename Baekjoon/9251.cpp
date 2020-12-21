#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

//구글 찬스.. LCS 알고리즘

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);

	char a[1001], b[1001];
	int dp[1001][1001], i,j;

	scanf("%s %s", a + 1, b + 1);

	
	for (i = 1; a[i]; i++)
	{
		for (j = 1; b[j]; j++)
		{		
			dp[i][j] = max({dp[i][j - 1],
							dp[i - 1][j],
							dp[i - 1][j - 1] + (a[i] == b[j])
				});
		} 
	}

	cout << dp[i - 1][j - 1] << endl;
	return 0;
}
