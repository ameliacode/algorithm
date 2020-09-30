#include<iostream>
#include<queue>
#include<vector>
#include<cstdio>

using namespace std;

int main()
{
	int N;
	int num = 2;

	cin >> N;

	while (N > 1) {
		if (N % num == 0) {
			cout << num << endl;
			N = N / num;
		}
		else {
			num++;
		}
	}
	
	return 0;
}