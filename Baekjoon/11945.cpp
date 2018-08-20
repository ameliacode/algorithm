#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);

	int N, M;
	cin >> N >> M;

	vector<string> ppangs;

	for (int i = 0; i < N; i++)
	{
		string ppang;
		cin >> ppang;
		reverse(ppang.begin(), ppang.end());
		ppangs.push_back(ppang);
	}

	for (int i = 0; i < N; i++)
	{
		cout << ppangs[i] << endl;
	}

	return 0;
}
