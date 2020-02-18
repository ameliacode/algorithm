#include<iostream>
#include<string>

using namespace std;

int SnailTrail(int A, int B, int V) {
	return (V - B - 1) / (A - B) + 1;
}

int main() {
	int A, B, V;
	cin >> A >> B >> V;
	cout << SnailTrail(A, B, V) << endl;
}