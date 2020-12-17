#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//구글 찬스.. 앞 뒤로 조사해서 합한다 → 손으로 이해하는 것이 더 빠름

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);

	int N;
	vector<int> S;
	

	cin >> N;
	vector<int> dp(N);
	vector<int> rdp(N);

	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;

		S.push_back(input);
	}

	for (int i = 0; i < N; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (S[j] < S[i] && dp[i] < dp[j] + 1) { // 오름차순이고 이전 갯수가 현재 갯수보다 작다면
				dp[i] = dp[j] + 1;
			}
		}
	}

	for(int i = N - 1;i >= 0;i--) {		//거꾸로 생각
		rdp[i] = 1;
		for (int j = N - 1; j > i; j--) {
			if (S[i] > S[j] && rdp[i] < rdp[j] + 1) {
				rdp[i] = rdp[j] + 1;
			}
		}
	}

	int result = 1;
	for (int i = 0; i < N; i++)
	{
		result = max(result, dp[i] + rdp[i] - 1);	
	}
	cout << result << endl;

	return 0;
}