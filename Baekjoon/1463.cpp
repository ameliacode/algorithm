#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<deque>

using namespace std;
int total = 0;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int X;

	cin >> X;

	int DP[10000] = { 0, };		//연산횟수 저장

	for (int i = 2; i <= X; i++) {	//i가 해당 숫자라고 하자, 
		DP[i] = DP[i - 1] + 1;	
		if (i % 2 == 0) DP[i] = min(DP[i], DP[i / 2] + 1);	//DP[i-1]에서 1을 더한 것이 더 큰 것인지 or 2를 곱한 연산이 더 작은지,
		if (i % 3 == 0) DP[i] = min(DP[i], DP[i / 3] + 1);  //DP[i-1]에서 1을 더한 것이 더 큰 것인지 or 3를 곱한 연산이 더 작은지,
	}

	for (int i = 0; i <= X; i++) {
		cout << DP[i] << " ";
	}
	
	cout << DP[X] << endl;

	return 0;
}