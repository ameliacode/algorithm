#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	
	string str1;
	
	cin >> str1;

	string str2 = str1;
	reverse(str2.begin(), str2.end());

	if (str2 == str1)
		cout << "1" << endl;
	else
		cout << "0" << endl;
	
	return 0;
}
