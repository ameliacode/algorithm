#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		cout << str[0] << str[str.length() - 1] << endl;
	}
	
	return 0;
}
