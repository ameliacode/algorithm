//#include<stdio.h>
//#include<stdlib.h>
//#define TRUE 1
//#define FALSE 0
//#define MAX_VERTEX 100
//#define INF 50000
//
//typedef struct graphType {
//	int n;
//	int adjMatrix[MAX_VERTEX][MAX_VERTEX];
//}graphType;
//
//int A[MAX_VERTEX][MAX_VERTEX];
//
//void createGraph(graphType *g) {
//	int i, j;
//	g->n = 1;
//	for (i = 0; i < MAX_VERTEX; i++) {
//		for (j = 0; j < MAX_VERTEX; j++) {
//			g->adjMatrix[i][j] = INF;
//		}
//	}
//}
//
//void insertVertex(graphType *g, int v) {
//	if (((g->n) + 1) > MAX_VERTEX) {
//		printf("-1\n");
//		return;
//	}
//
//	g->n++;
//}
//
//void insertEdge(graphType* g, int u, int v, int w) {
//	if (u >= g->n || v >= g->n) {
//		printf("-1\n");
//		return;
//	}
//	g->adjMatrix[u][v] = w;
//}
//
//void Floyd_shortestPath(graphType *G, int n) {
//	int v, w, k, step = -1;
//
//	for (v = 1; v <= n; v++) {
//		for (w = 1; w <= n; w++) {
//			A[v][w] = G->adjMatrix[v][w];
//		}
//	}
//
//	for (k = 1; k <= n; k++) {
//		for (v = 1; v <= n; v++) {
//			for (w = 1; w <= n; w++) {
//				if ((A[v][k] + A[k][w] < A[v][w]) && A[v][k]!= INF && A[k][w] != INF) {			//if route doesn't exists (as INFINITE ROUTE = NO ROUTE) ignore
//					A[v][w] = A[v][k] + A[k][w];
//				}
//			}
//		}
//	}
//}
//
//int main() {
//
//	graphType *G;
//	G = (graphType*)malloc(sizeof(graphType));
//	createGraph(G);
//
//	int n, m, s, u, v, w, i, j;
//
//	scanf("%d %d %d", &n, &m, &s);
//	getchar();
//
//	for (i = 0; i < n; i++) {
//		insertVertex(G, i);
//	}
//
//	for (i = 0; i < m; i++) {
//		scanf("%d %d %d", &u, &v, &w);
//		getchar();
//		insertEdge(G, u, v, w);
//	}
//	Floyd_shortestPath(G, n);
//
//	for (i = 1; i <= n; i++) {
//		if (i == s) continue;
//		else {
//			if (A[s][i] != INF) {	//if edge doesn't exists
//				printf("%d %d\n", i, A[s][i]);
//			}
//		}	
//	}
//	return 0;
//}