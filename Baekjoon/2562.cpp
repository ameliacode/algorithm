#include<iostream>
using namespace std;

int main() {
	
	int N = 9;
	int max = 0, index = 0;
	int *p = new int[N];

	for (int i = 0; i < N; i++) {
		cin >> p[i];
		if (max < p[i]) {
			max = p[i];
			index = i;
		}
	}

	cout << max << endl;
	cout << index + 1<< endl;

	return 0;
}
