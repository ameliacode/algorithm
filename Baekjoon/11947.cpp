#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 구글 찬스: 수학적으로 접근해야 하는 문제, 문제 그대로 해석 X
long long reverse_num(long long n)
{
	long long exp = 1;
	while (n >= exp)
	{
		exp *= 10;
	}
	return exp - 1 - n;
}

long long biggest(long long n)
{
	long long exp = 1;
	while (n >= exp)
	{
		exp *= 10;
	}
	return min((exp / 2) - 1, n);

}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		long long input;
		cin >> input;
		
		long long target = biggest(input);
		cout << target * reverse_num(target) << endl;
	}

	return 0;
}
