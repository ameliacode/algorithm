#include<iostream>
#include<algorithm>
#include<cstdio>
#include<deque>
#include<string>

using namespace std;

/*deque<int> R(deque<int> dq, int size){
	deque<int> inv_dq;

	for (int j = 0; j < size;j++) {
		inv_dq.push_back(dq.back());
		dq.pop_back();
	}
	return inv_dq;
}*/

int main() {

	cin.tie(0);
	cin.sync_with_stdio(0);

	int T, n;
	string oper, input;

	cin >> T;

	for (int i = 0; i < T; i++) {

		int num = 0;
		bool reverse = false;
		bool isError = false;
		deque<int> dq;

		cin >> oper >> n >> input;
		
		for (int j = 0; j < input.size(); j++) {
			if ('0' <= input[j] && input[j] <= '9') {
				num = num * 10;
				num = num + int(input[j] - '0');
			}
			else{
				if (num != 0) {
					dq.push_back(num);
					num = 0;
				}
			}
		}


		for (int j = 0; j < oper.size(); j++) {
			if (oper[j] == 'R') 
			{
				//dq = R(dq, dq.size());	//시간 초과
				reverse = !reverse;
			}
			else if (oper[j] == 'D') 
			{
				if (dq.empty()) {
					isError = true;
					cout << "error" << endl;
					break;
				}
				//else dq.pop_front();
				else {
					if (reverse)
						dq.pop_back();
					else
						dq.pop_front();
				}
			}
		}

		if (isError) continue;
 	
		cout << "[";
		if (reverse) {
			while (dq.size()) {
				cout << dq.back();
				dq.pop_back();
				if (dq.size()) {
					cout << ",";
				}
			}
		}
		else {
			while (dq.size()) {
				cout << dq.front();
				dq.pop_front();
				if (dq.size()) {
					cout << ",";
				}
			}
		}
		cout << "]" << endl;
	}
	return 0;
}