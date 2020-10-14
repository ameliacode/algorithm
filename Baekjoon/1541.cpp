#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>
#include<algorithm>

using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int answer = 0;
	string temp;
	bool oper = false;
	string calc;
	cin >> calc;

	for (int i = 0; i <= calc.size(); i++) {
		if (calc[i] == '-' || calc[i] == '+' || i==calc.size()) {
			if (oper) {
				answer -= stoi(temp);
			}
			else {
				answer += stoi(temp);
			}

			if (calc[i] == '-') {
				oper = true;
			}
			temp = "";

		}
		else temp += calc[i];
		//cout << temp << endl;
	}

	cout << answer << endl;

	return 0;
}