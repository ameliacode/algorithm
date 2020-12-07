#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAX_VERTEX 100
#define INF 30000

typedef struct graphType {
	int n;
	int adjMatrix[MAX_VERTEX][MAX_VERTEX];
}graphType;

int dist[MAX_VERTEX];
int selected[MAX_VERTEX];
int totalWeight = 0;

void createGraph(graphType* g) {
	int i, j;
	g->n = 1;
	for (i = 0; i < MAX_VERTEX; i++) {
		for (j = 0; j < MAX_VERTEX; j++) {
			g->adjMatrix[i][j] = INF;
		}
	}
}

void insertVertex(graphType* g, int v) {
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

void print_adjMatrix(graphType* g) {
	int i, j;
	for (i = 1; i < (g->n); i++) {
		for (j = 1; j < (g->n); j++) {
			if (i == j) {
				printf(" 0");
			}
			else if (g->adjMatrix[i][j] == INF) {
				printf(" *");
			}	
			else {
				printf(" %d", g->adjMatrix[i][j]);
			}			
		}
		printf("\n");
	}
}

int main() {
	int n, m, i, u, v, w;
	graphType* G = (graphType*)malloc(sizeof(graphType));
	createGraph(G);

	scanf("%d %d", &n, &m);

	for (i = 1; i <= n; i++) {
		insertVertex(G, i);
	}

	for (i = 0; i < m; i++) {
		scanf("%d %d %d", &u, &v, &w);
		insertEdge(G, u, v, w);
	}
	print_adjMatrix(G);

	return 0;

}