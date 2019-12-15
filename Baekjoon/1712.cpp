#include<iostream>
#include<string>

using namespace std;

int BreakEvenPoint(int A, int B, int C) {
	int total = -1;
	if ((C - B) > 0) total = A / (C - B) + 1;
	return total;
}

int main() {
	int A, B, C;
	cin >> A >> B >> C;
	cout << BreakEvenPoint(A, B, C) << endl;

	return 0;
}
