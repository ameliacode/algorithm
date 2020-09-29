#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<stack>

using namespace std;

int main()
{
	int K;	
	bool isRight = true;
	cin >> K;

	for (int i = 0; i < K; i++) {

		stack<char> v;
		string input;
		cin >> input;
		isRight = true;

		for (int j = 0; j < input.size(); j++) {
			
			if (input[j] == '(') {
				v.push(input[j]);
			}

			if (input[j] == ')') {
				if (!v.empty()){
					v.pop();
				}

				else {
					isRight = false;
					break;
				}
			}	
		}

		if (isRight && v.empty()) cout << "YES" << endl;
		else cout << "NO" << endl;
	}


	return 0;
}