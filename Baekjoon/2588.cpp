#include<iostream>
using namespace std;

int main() {

	int a;
	int b;
	int save[3];

	cin >> a;
	cin >> b;
	save[0] = a * (b % 10);
	cout <<  save[0] << endl;
	b = b / 10;

	save[1] = a * (b % 10);
	cout << save[1] << endl;
	b = b / 10;

	save[2] = a * (b % 10);
	cout << save[2] << endl;

	cout << save[0] + (save[1]*10) + (save[2]*100) << endl;

	return 0;
}
