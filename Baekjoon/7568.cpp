#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstdio>

using namespace std;

int main()
{
	int N; 
	int rank = 1;

	cin >> N;
	vector<pair<int, int>> student(N);

	for (int i = 0; i < N; i++) {
		cin >> student[i].first >> student[i].second;
	}
	

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int weight1 = student[i].first;
			int height1 = student[i].second;
			int weight2 = student[j].first;
			int height2 = student[j].second;

			if (weight2 > weight1 && height2 > height1) {
				rank++;
			}
		}
		cout << rank << endl;
		rank = 1;
	}
	
	return 0;
}