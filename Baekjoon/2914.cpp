#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	
	int A, I;
	cin >> A >> I;
	
	cout << A * (I - 1)  + 1 << endl;

	return 0;
}
