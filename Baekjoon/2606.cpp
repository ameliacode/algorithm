#include<iostream>
#include<vector>
#include<cstring>	#memset
#include<queue>
#include<algorithm>

using namespace std;

bool visited[1001];
bool graph[1001][1001];
int N, M;
int total = 0;

void DFS(int v) {
	//cout << v << " ";
	visited[v] = true;
	for (int i = 1; i <= N; i++) {
		if (graph[v][i] && !visited[i]) {
			total++;
			DFS(i);
		}
	}
}

void BFS(int v) {
	queue<int> q;
	visited[v] = true;
	q.push(v);

	while (!q.empty()) {
		v = q.front();
		q.pop();
		//cout << v << " ";

		for (int i = 1; i <= N; i++) {
			if (graph[v][i] && !visited[i]) {
				q.push(i);
				visited[i] = true;
			}
		}
	}
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	cin >> N >> M;
	memset(graph, false, sizeof(graph));
	
	for (int i = 0; i < M; i++) {
		int start, end;
		cin >> start >> end;
		graph[start][end] = true;
		graph[end][start] = true;
	}

	memset(visited,false, sizeof(visited)); DFS(1); 
	cout << total << endl;

	return 0;
}