#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);

	int a, b, c, d;
	cin >> a >> b >> c >> d;

	int min_count = min(b + c, a + d);
	cout << min_count << endl;
	
	return 0;
}
