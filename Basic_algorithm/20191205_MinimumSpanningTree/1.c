#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAX_VERTEX 100
#define INF 1000

typedef struct graphType {
	int n;
	int adjMatrix[MAX_VERTEX][MAX_VERTEX];
}graphType;

int dist[MAX_VERTEX];
int selected[MAX_VERTEX];
int totalWeight = 0;

void createGraph(graphType *g) {
	int i, j;
	g->n = 1;
	for (i = 0; i < MAX_VERTEX; i++) {
		for (j = 0; j < MAX_VERTEX; j++) {
			g->adjMatrix[i][j] = INF;
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

void print_adjMatrix(graphType *g) {
	int i, j;
	for (i = 1; i < (g->n); i++) {
		for (j = 1; j < (g->n); j++) {
			printf("%2d", g->adjMatrix[i][j]);
		}
		printf("\n");
	}
}

int removeMin(int n) {
	int v, i;
	for (i = 1; i < n; i++) {
		if (!selected[i]) {
			v = i;
			break;
		}
	}
	for (i = 1; i < n; i++) {
		if (!selected[i] && (dist[i] < dist[v]))
			v = i;
	}
	return v;
}

void PrimJarnikMST(graphType *G) {
	int i, u, v, s = 1;
	int k = 0;

	for (u = 1; u < G->n; u++) {
		dist[u] = INF;
		selected[u] = FALSE;
	}

	dist[s] = 0;

	for (i = 1; i < G->n; i++) {
		u = removeMin(G->n);
		selected[u] = TRUE;
		if (dist[u] == INF) return;
		printf(" %d", u);
		for (v = 1; v < G->n; v++) {
			if (G->adjMatrix[u][v] != INF) {
				if (!selected[v] && (G->adjMatrix[u][v] < dist[v])) {
					dist[v] = G->adjMatrix[u][v];
				}
			}
		}
	}

	for (k = 1; k < G->n; k++) {
		totalWeight += dist[k];
	}
}


int main() {
	int n, m, i, u, v, w;
	graphType *G = (graphType*)malloc(sizeof(graphType));
	createGraph(G);

	scanf("%d %d", &n, &m);

	for (i = 1; i <= n; i++) {
		insertVertex(G, i);
	}

	for (i = 0; i < m; i++) {
		scanf("%d %d %d", &u, &v, &w);
		insertEdge(G, u, v, w);
		insertEdge(G, v, u, w);
	}
	//print_adjMatrix(G);

	PrimJarnikMST(G);
	printf("\n%d\n", totalWeight);

	return 0;

}