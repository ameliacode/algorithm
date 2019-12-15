#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAX_VERTEX 101
#define INF 20000

typedef struct graphType {
	int n;
	int adjMatrix[MAX_VERTEX][MAX_VERTEX];
}graphType;

int distance[MAX_VERTEX];
int S[MAX_VERTEX];

void createGraph(graphType *g) {
	int i, j;
	g->n = 1;
	for (i = 0; i < MAX_VERTEX; i++) {
		for (j = 0; j < MAX_VERTEX; j++) {
			if (i == j) g->adjMatrix[i][j] = 0;
			else g->adjMatrix[i][j] = INF;
		}
	}
}

void insertVertex(graphType *g, int v) {
	if (((g->n) + 1) > MAX_VERTEX) {
		printf("-1\n");
		return;
	}

	g->n++;
}

void insertEdge(graphType* g, int u, int v, int w) {
	if (u >= g->n || v >= g->n) {
		printf("-1\n");
		return;
	}
	g->adjMatrix[u][v] = w;
}

int nextVertex(int n) {
	int i, min, minPos;
	min = INF;
	minPos = -1;
	for (i = 1; i <= n; i++) {
		if ((distance[i] < min) && !S[i]) {
			min = distance[i];
			minPos = i;
		}
	}
	return minPos;
}

void Dijkstra_shortestPath(graphType *G, int start, int n) {
	int i, u, w, step = 0;

	for (i = 1; i <= n; i++) {
		distance[i] = G->adjMatrix[start][i];
		S[i] = FALSE;
	}

	S[start] = TRUE; 
	distance[start] = 0;

	for (i = 1; i <= n - 1; i++) {
		u = nextVertex(n);
		S[u] = TRUE;
		for (w = 1; w <= n; w++) {
			if (!S[w]) {
				if (distance[u] + G->adjMatrix[u][w] < distance[w]) {
					distance[w] = distance[u] + G->adjMatrix[u][w];
				}
			}
		}
	}

	for (i = 1; i <= n; i++) {
		if (i != start && distance[i] != 0 && distance[i] != INF) printf("%d %d\n", i, distance[i]);
	}
}

int main() {

	graphType *G;
	G = (graphType*)malloc(sizeof(graphType));
	createGraph(G);

	int n, m, s, u, v, w, i;

	scanf("%d %d %d", &n, &m, &s);
	getchar();

	for (i = 0; i < n; i++) {
		insertVertex(G, i);
	}

	for (i = 0; i < m; i++) {
		scanf("%d %d %d", &u, &v, &w);
		getchar();
		insertEdge(G, u, v, w);
		insertEdge(G, v, u, w);
	}
	Dijkstra_shortestPath(G, s, n);

	return 0;
}