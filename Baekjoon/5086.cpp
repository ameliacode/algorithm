#include<iostream>
#include<queue>
#include<vector>
#include<cstdio>

using namespace std;

int main()
{
	int a, b;
	
	while (true) {
		cin >> a >> b;
		
		if (a == 0 && b == 0)
			break;

		string result;

		if (a < b) {
			if (b % a == 0) {
				result = "factor";
			}
			else {
				result = "neither";
			}
		}
		else if (a > b) {
			if (a % b == 0) {
				result = "multiple";
			}
			else {
				result = "neither";
			}
		}

		cout << result << endl;
	}
	
	return 0;
}