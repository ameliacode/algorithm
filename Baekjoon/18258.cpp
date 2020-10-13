#include<iostream>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;

int main() {

cin.tie(0);
cin.sync_with_stdio(0);
	int N;
	cin >> N;
	queue<int> q;

	for (int i = 0; i < N; i++) {
		string oper;
		cin >> oper;
	
		if (oper == "push") {
			int X;
			cin >> X;
			q.push(X);
		}
		else if (oper == "pop") {
			if (q.empty()) printf("-1\n");
			else {
				printf("%d\n",q.front());
				q.pop();
			}
		}
		else if (oper == "size") {
			printf("%d\n", q.size());
		}
		else if (oper == "empty") {
			printf("%d\n", q.empty());
		}
		else if (oper == "front") {
			if (q.empty())  printf("-1\n");
			else printf("%d\n",q.front());
		}
		else if (oper == "back") {
			if (q.empty()) printf("-1\n");
			else printf("%d\n",q.back());
		}
	}
	return 0;
}