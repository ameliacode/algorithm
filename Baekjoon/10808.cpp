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
	
	string str;
	cin >> str;

	int alphabet[26] = { 0, };
	for (int i = 0; i < str.length(); i++)
	{
		int index = 0;
		while (index < 26)
		{
			if (str[i] == 'a' + index)
			{
				alphabet[index]++;
			}
			index++;
		}
	}

	for (int i = 0; i < 26; i++)
	{
		cout << alphabet[i] << " ";
	}
	return 0;
}
