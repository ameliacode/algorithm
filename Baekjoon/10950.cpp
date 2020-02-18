#include<iostream>
using namespace std;

int main() {
	
	int a, b;
	int N;

	cin >> N;
	while (N) {
		cin >> a >> b;
		cout << a + b << endl;
		N--;
	}

	return 0;
}