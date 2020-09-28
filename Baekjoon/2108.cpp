#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

bool compare(int a, int b)
{
	return a < b;
}


int main()
{
	int N;
	double total = 0;
	int max_value = -4000;
	int min_value = 4000;
	int max_count = -1;

	cin >> N;

	vector<int> arr(N);
	int mode_arr[8005] = { 0 };

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		total += arr[i];
		
		int index = arr[i] + 4000;
		mode_arr[index]++;

		max_value = max(max_value, arr[i]);
		min_value = min(min_value, arr[i]);
		max_count = max_count < mode_arr[index] ? mode_arr[index] : max_count;
	}

	int mode = 0;
	int range = 0;

	if (N != 1) {
		int flag = 0;					  //"두 번째" 조건
		int cnt = 0;
		for (int i = 0; i < 8005; i++) {  //최빈값 갯수 counting
			if (max_count == mode_arr[i]) {
				cnt++;
			}
		}


		for (int i = 0; i < 8005; i++) {
			if (max_count == mode_arr[i]) {
				if (cnt == 1) {				//최빈값이 하나만 있을 경우
					mode = i - 4000;
					break;
				}
				else {
					if (flag == 0) {		//최빈값이 여러개 일 경우
						flag = 1;
					}
					else if (flag == 1) {
						mode = i - 4000;
						break;
					}
				}	
				
				
			}
		}
		range = max_value - min_value;		//범위


	}
	else {
		mode = arr[0];
		range = 0;
	}
		

	sort(arr.begin(), arr.end(), compare);

	int mean = (int)floor(total / N + 0.5f);				//평균값
	int median = arr[N / 2];								//중앙값

	cout << mean << endl;
	cout << median << endl;
	cout << mode << endl;
	cout << range << endl;
	
	return 0;
}