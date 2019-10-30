#include<iostream>
#include<string> 
#include<stack>

using namespace std;

int _pow(int a, int b) {
	int total = 1;
	for (int i = 0; i < b; i++) {
		total *= a;
	}
	return total;
}

int main() {
	string input;
	stack<int> Stack;
	stack<int> temp;
	int total = 0, insert = 0;
	int Single, Double, Triple;
	int Arch;
	cin >> input;

	for (int i = 0; i < input.size(); i++) {
		switch (input[i]) {
		case 'S':
			Single = _pow(Stack.top(), 1);
			Stack.pop(); Stack.push(Single);
			//cout << "Single!" << endl;
			break;
		case 'D':
			Double = _pow(Stack.top(), 2);
			Stack.pop(); Stack.push(Double);
			//cout << "Double!" << endl;
			break;
		case 'T':
			Triple = _pow(Stack.top(), 3);
			Stack.pop(); Stack.push(Triple);
			//cout << "Triple!" << endl;
			break;
		case '*':
			while (!Stack.empty()) {
				temp.push(Stack.top() * 2);
				Stack.pop();
			}
			while (!temp.empty()) {
				Stack.push(temp.top());
				temp.pop();
			}
			break;
		case '#':
			Arch = Stack.top();
			Stack.pop();
			Stack.push(Arch*-1);
			break;
		default:
			for (int j = i;; j++) {
				if ('0' <= input[j] && input[j] <= '9') {
					insert += input[j] - '0';
					insert = insert * 10;
				}
				else {
					i = j - 1;
					break;
				}
			}
			insert = insert / 10;
			Stack.push(insert);
			insert = 0;
			break;
		}
	}
	for (int i = 0; !Stack.empty(); i++) {
		total += Stack.top();
		Stack.pop();
	}
	cout << total << endl;
}//copyright 2019 github @ ameliacode