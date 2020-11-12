#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//검색 찬스 사용
//문제 접근: 옆 숫자들을 빼서 공약수 구하는 것까지는 캐치
//최대공약수 활용과 시간초과 문제는 캐치 X

int GCD(int a, int b)
{
	if (a % b == 0) return b;
	else return GCD(b, a % b);
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);

	int n;
	cin >> n;

	vector<int> v;
	vector<int> answer;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	int gcd = v[1] - v[0];

	for (int i = 1; i < n; i++) {
		gcd = GCD(gcd, v[i] - v[i-1]);
	}

	for (int i = 2; i*i <= gcd; i++) {
		if (gcd % i == 0)
		{
			answer.push_back(i);
			answer.push_back(gcd/i);
		}
	}

	answer.push_back(gcd);
	sort(answer.begin(), answer.end());
	answer.erase(unique(answer.begin(), answer.end()), answer.end());

	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << " ";
	}



	return 0;
}