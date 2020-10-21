#include<iostream>
#include<vector>
#include<cstring>	#memset
#include<queue>
#include<algorithm>

using namespace std;

int visited[1001];
int graph[1001][1001];
int N, M, V;

void DFS(int v) {
	cout << v << " ";
	visited[v] = 1;
	for (int i = 1; i <= N; i++) {
		if (graph[v][i] && !visited[i]) {
			DFS(i);
		}
	}
}

void BFS(int v) {
	queue<int> q;
	visited[v] = 1;
	q.push(v);

	while (!q.empty()) {
		v = q.front();
		q.pop();
		cout << v << " ";

		for (int i = 1; i <= N; i++) {
			if (graph[v][i] && !visited[i]) {
				q.push(i);
				visited[i] = 1;
			}
		}
	}
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	cin >> N >> M >> V;
	memset(graph, 0, sizeof(graph));
	
	for (int i = 0; i < M; i++) {
		int start, end;
		cin >> start >> end;
		graph[start][end] = 1;
		graph[end][start] = 1;
	}

	memset(visited,0, sizeof(visited)); DFS(V); cout << endl;
	memset(visited,0, sizeof(visited)); BFS(V); cout << endl;

	return 0;
}