#include<iostream>
#include<cstdio>
#include<string>
#include<deque>
#include<vector>

using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int N;
	cin >> N;

	int num = 666;

	while (N > 0) {
		string title = to_string(num++);
		if (title.find("666") != -1) {	
			N--;
		}
	}

	cout << num - 1 << endl;

	return 0;
}