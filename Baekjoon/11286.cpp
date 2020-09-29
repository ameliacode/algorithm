#include<iostream>
#include<queue>
#include<vector>
#include<cstdio>

using namespace std;

int main()
{
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
	int N;

	scanf("%d", &N);					//시간 초과 문제 해결

	for (int i = 0; i < N; i++) {
		int x;
		scanf("%d", &x);

		if (x == 0) {
			if (!q.empty()) {
				printf("%d\n", q.top().second); //시간 초과 문제 해결
				q.pop();
			}
			else {
				printf("0\n");			//시간 초과 문제 해결
			}
		}
		else {
			q.push(make_pair(abs(x),x));
		}		
	}
	return 0;
}