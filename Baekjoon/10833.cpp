#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	
	int N, answer = 0;
	int apples[100][2];

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> apples[i][0] >> apples[i][1];
		int each = apples[i][1] / apples[i][0];
		answer += apples[i][1] - (each * apples[i][0]);
	}

	cout << answer << endl;

	return 0;
}
