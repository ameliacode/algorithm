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

	int a, b, tmp;
	a = 0;
	b = 1;
	for (int i = 0; i < n; i++)
	{
		tmp = b;
		b = b + a;
		a = tmp;
	}

	cout << a << endl;

	return 0;
}
