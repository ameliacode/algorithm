#include<iostream>
using namespace std;

int main() {
	
	int N = 10;
	int num;
	int total = 0;
	int index = 0;
	int *p = new int[N];

	for (int i = 0; i < N; i++) {
		cin >> num;
		p[index++] = num % 42;
	}
	for (int i = 0; i < N; i++) {
		int flag = 0;
		for (int j = i+1; j < N; j++) {
			if (p[i] == p[j]) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) total++;
	}

	cout << total << endl;
	delete p;
	return 0;
}