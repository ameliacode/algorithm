#include<iostream>
using namespace std;

int main() {

	int year;
	bool isItYear = false;

	cin >> year;

	if (year % 4 == 0) {
		if (year % 400 == 0) isItYear = true;
		else if (year % 100 == 0) isItYear = false;
		else isItYear = true;
	}
	if (isItYear) cout << "1" << endl;
	else cout << "0" << endl;

	return 0;
}