#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cout << '*';
		}
		cout << endl;
	}
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < N - i; j++)
		{
			cout << '*';
		}
		cout << endl;
	}
	
	return 0;
}
