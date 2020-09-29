#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<stack>
#include<string>

using namespace std;

int main()
{
	int n;
	stack<int> v;
	vector<int> arr;
	char result[200000];

	cin >> n;

	for (int i = 0; i < n; i++) {		//배열 입력
		int input;
		cin >> input;

		arr.push_back(input);
	}

	int num = 1;
	int arr_index = 0;
	int index = 0;

	while (arr_index < n) {
		if (!v.empty()) {
			//cout << v.top() << " " << arr[arr_index] << endl;
			if (v.top() == arr[arr_index]) {
				v.pop();
				arr_index++;
				result[index++] = '-'; 
				continue;
			}
			else if (v.top() > arr[arr_index]) {
				printf("NO");			// 시간 초과 문제 해결
				return 0;
			}
		}		
		
		v.push(num);
		num++;
		result[index++] = '+';
	}
	
	for (int i = 0; i < index; i++) {
		printf("%c\n", result[i]);
	}

	return 0;
}