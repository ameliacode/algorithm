#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);

	int N, M;
	cin >> N >> M;

	string answer = "";
	for (int i = 0; i < N; i++)
	{
		answer += to_string(N);
	}

	cout << answer.substr(0,M) << endl;
	
	return 0;
}
