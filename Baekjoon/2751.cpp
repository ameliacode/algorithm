#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>

using namespace std;

int main() {

	int N;
	vector<int> arr;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int input;
		scanf("%d", &input);
		arr.push_back(input);
	}

	sort(arr.begin(), arr.end());

	for (int i = 0; i < N; i++) {
		printf("%d\n", arr[i]);
	}

	return 0;
}