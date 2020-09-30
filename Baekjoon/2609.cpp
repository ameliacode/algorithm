#include<iostream>
#include<queue>
#include<vector>
#include<cstdio>

using namespace std;

int gcd(int a, int b) {

	int num;

	while (b != 0) {
		num = a % b;
		a = b;
		b = num;
	}
	return a;
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

int main()
{
	int a ,b ;
	int num = 2;

	cin >> a >> b;

	cout << gcd(a, b) << endl;
	cout << lcm(a, b) << endl;
	
	return 0;
}