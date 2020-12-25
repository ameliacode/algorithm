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
	
	int count = 0;

	char vowels[5] = { 'a','e','i','o','u' };

	for (int i = 0; i < str.length(); i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (vowels[j] == str[i]) count++;
		}
	}

	cout << count << endl;
	
	return 0;
}
