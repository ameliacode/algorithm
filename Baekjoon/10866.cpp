#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<deque>

using namespace std;

int main() {

	int N;
	deque<int> dq;
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		string oper;
		cin >> oper;
		if (oper == "push_back") {
			int input;
			cin >> input;
			dq.push_back(input);
		}
		else if (oper == "push_front") {
			int input;
			cin >> input;
			dq.push_front(input);
		}
		else if (oper == "pop_front") {
			if (dq.empty()) cout << "-1" << endl;
			else {
				cout << dq.front() << endl;
				dq.pop_front();
			}
		}
		else if (oper == "pop_back") {
			if (dq.empty()) cout << "-1" << endl;
			else {
				cout << dq.back() << endl;
				dq.pop_back();
			}
		}
		else if (oper == "size") {
			cout << dq.size() << endl;
		}
		else if (oper == "empty") {
			if (dq.empty()) cout << "1" << endl;
			else cout << "0" << endl;
		}
		else if (oper == "front") {
			if (dq.empty()) cout << "-1" << endl;
			else cout << dq.front() << endl;
		}
		else if (oper == "back") {
			if (dq.empty()) cout << "-1" << endl;
			else cout << dq.back() << endl;
		}
	}

	return 0;
}