#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	
	string str;

	cin >> str;

	int joi_count = 0;
	int ioi_count = 0;

	for (int i = 0; i < str.length(); i++)
	{
		if (str.substr(i, 3) == "JOI") {
			joi_count++;
		}
		else if (str.substr(i, 3) == "IOI") {
			ioi_count++;
		}
	}

	cout << joi_count << endl;
	cout << ioi_count << endl;
	 
	return 0;
}
