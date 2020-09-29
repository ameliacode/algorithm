#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<stack>
#include<string>

using namespace std;

int main()
{
	bool isRight = true;

	while (true){

		stack<char> v;
		string input;
		getline(cin, input);

		if (input[0] == '.') break;
		isRight = true;

		for (int j = 0; j < input.size(); j++) {
			
			if (input[j] == '(' || input[j] == '[' ) {
				v.push(input[j]);
			}

			if (input[j] == ')' || input[j] == ']') {
				if (!v.empty()){
					if ((v.top() == '(' && input[j] == ')') ||
						(v.top() == '[' && input[j] == ']') ){
						v.pop();
					}
					else {
						isRight = false;
						break;
					}
				}
				else {
					isRight = false;
					break;
				}
			}	
		}

		if (isRight && v.empty()) cout << "yes" << endl;
		else cout << "no" << endl;
	}


	return 0;
}