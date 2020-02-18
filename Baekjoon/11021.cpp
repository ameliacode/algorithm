#include<iostream>
using namespace std;

int main() {
	
	int a, b;
	int N;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		cout << "Case #" << i + 1 <<": "<< a + b << endl;
	}
	
	return 0;
}