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

	int N;

	int stack[1000][3];
	int input[1000][3];
	
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> input[i][j];
		}
	}

	stack[0][0] = input[0][0];
	stack[0][1] = input[0][1];
	stack[0][2] = input[0][2];
	

	for (int i = 1; i < N; i++) {
		stack[i][0] = min(stack[i - 1][1], stack[i - 1][2]) + input[i][0];
		stack[i][1] = min(stack[i - 1][0], stack[i - 1][2]) + input[i][1];
		stack[i][2] = min(stack[i - 1][0], stack[i - 1][1]) + input[i][2];
	}

	cout << min(min(stack[N-1][0],stack[N-1][1]),stack[N-1][2]) << endl;

	return 0;
}