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

	int car = 0;
	for (int i = 0; i < 5; i++)
	{
		int cars;
		cin >> cars;
		if (N == cars) car++;
	}

	cout << car << endl;

	return 0;
}
