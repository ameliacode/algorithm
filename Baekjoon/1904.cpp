#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;
int total = 0;

int main() {
	int a = 0, b = 1;
	int n, temp;
	
	cin >> n;

	for (int i = 0; i < n; i++) {
		temp = b;
		b = (b + a) % 15746;		//범위를 초과하기 때문에 미리 나머지 값을 저장
		a = temp;
	}

	cout << b << endl;
	return 0;
}