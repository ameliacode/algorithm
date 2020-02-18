#include<iostream>
using namespace std;

int main() {
	
	int N;
	int total = 1;
	cin >> N;
	
	if (N == 0) cout << "1" << endl;
	else {
		for (int i = 1; i <= N; i++) {
			total *= i;
		}
		cout << total << endl;
	}
}