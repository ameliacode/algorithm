#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

bool compare(int a, int b) {
	return a > b;
}

int main()
{
	int N;
	cin >> N;
	vector<int> arr;
	
	while (N > 0)
	{
		arr.push_back(N % 10);
		N = N / 10;
	}
	sort(arr.begin(), arr.end(), compare);

	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i];
	}
	return 0;
}