#include <iostream>
#include <string>


using namespace std;

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);

	string id;
	cin >> id;

	for (int i = 0; i < 3; i++) cout << ":fan:";
	cout << endl;
	cout << ":fan::" << id << "::fan:" << endl;
	for (int i = 0; i < 3; i++) cout << ":fan:";
	return 0;
}
