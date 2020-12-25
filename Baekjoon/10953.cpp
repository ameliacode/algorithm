#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

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
		string buffer;
		istringstream ss(str);
		vector<string> x;

		while (getline(ss, buffer, ',')) {
			x.push_back(buffer);
		}
		cout << stoi(x[0]) + stoi(x[1]) << endl;
		
	}
	return 0;
}
