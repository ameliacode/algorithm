#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	
	int total;
	cin >> total;

	for (int i = 0; i < 9; i++) {
		int price;
		cin >> price;
		total -= price;
	}
	cout << total << endl;

	return 0;
}
