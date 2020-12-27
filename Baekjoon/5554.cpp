#include <iostream>

using namespace std;

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);

	int secs = 0;
	
	for (int i = 0; i < 4; i++)
	{
		int sec;
		cin >> sec;
		secs += sec;
	}

	cout << secs / 60 << endl;
	cout << secs % 60 << endl;
	
	return 0;
}
