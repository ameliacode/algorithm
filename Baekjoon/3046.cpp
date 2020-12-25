#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	
	int r1, s;

	cin >> r1 >> s;
	
	cout << s + (s - r1) << endl;

	return 0;
}
