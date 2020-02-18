#include<iostream>
using namespace std;

int main() {
	
	int N;
	int min = 10000001, max = -10000001;
	cin >> N;
	int *p = new int[N];

	for (int i = 0; i < N; i++) {
		cin >> p[i];
		if (min > p[i])min = p[i];
		if (max < p[i])max = p[i];
	}
	cout << min << " " << max << endl;
	
	return 0;
}