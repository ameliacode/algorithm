#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);

	string A;
	string B;
	string answer = "";

	cin >> A >> B;

	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());

	int length = min(A.length(), B.length());
	int ten = 0;

	for (int i = 0; i < length; i++)
	{
		int temp = (A[i] - '0') + (B[i] - '0') + ten;
		answer = to_string(temp % 10) + answer;
		ten = temp / 10;
	}
	
	if (A.length() > B.length())
	{

		for (int i = B.length(); i < A.length(); i++)
		{
			int temp = (A[i] - '0') + ten;
			answer = to_string(temp % 10) + answer;
			ten = temp / 10;
		}
	}
	else if (A.length() < B.length())
	{
		for (int i = A.length(); i < B.length(); i++)
		{
			int temp = (B[i] - '0') + ten;
			answer = to_string(temp % 10) + answer;
			ten = temp / 10;
		}
	}
	if(ten != 0) answer = to_string(ten) + answer; //예제 확인해서 오류 찾음!

	cout << answer << endl;

	return 0;
}
