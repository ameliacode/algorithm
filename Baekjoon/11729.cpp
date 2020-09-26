#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

vector<pair<int, int>> v;
void hanoi(int n, int start, int work, int target) {
	if (n == 1) {
		v.push_back(make_pair(start, target));
	}
	else {
		hanoi(n - 1, start, target, work);
		v.push_back(make_pair(start, target));
		hanoi(n - 1, work, start, target);
	}
}

int main()
{
	long long N;
	cin >> N;

	hanoi(N, 1, 2, 3);

	printf("%d\n", v.size()); //printf가 cout보다 더 빠르기 때문에 변경 (시간초과 문제 해결)
	for (int i = 0; i < v.size(); i++) {
		printf("%d %d\n", v[i].first, v[i].second);
	}
	return 0;
}
