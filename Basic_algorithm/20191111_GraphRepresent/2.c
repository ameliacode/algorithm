#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTEX 21

//adjacent matrix implementation using array 
typedef struct graphType {
	int n;
	int adjMatrix[MAX_VERTEX][MAX_VERTEX];
}graphType;

void createGraph(graphType *g) {
	int i, j;
	g->n = 1;
	for (i = 0; i < MAX_VERTEX; i++) {
		for (j = 0; j < MAX_VERTEX; j++) {
			g->adjMatrix[i][j] = 0;
		}
	}
}

void insertVertex(graphType *g, int v) {
	if (((g->n) + 1) > MAX_VERTEX) {
		printf("-1\n");									//exception
		return;
	}

	g->n++;
}

void insertEdge(graphType* g, int u, int v, int w) {	//inserting edges & weight
	if (u >= g->n || v >= g->n) {						//exception
		printf("-1\n");
		return;
	}
	g->adjMatrix[u][v] = w;
}

void print_adjMatrix(graphType *g) {					//checking matrix
	int i, j;
	for (i = 1; i < (g->n); i++) {
		for (j = 1; j < (g->n); j++) {
			printf("%2d", g->adjMatrix[i][j]);
		}
		printf("\n");
	}
}

void printNode(graphType *g, int node) {				// oper a
	int i;
	if (node >= g->n) {
		printf("-1");
	}
	else {
		for (i = 1; i < g->n; i++) {
			if (g->adjMatrix[node][i] != 0) {
				printf(" %d %d", i, g->adjMatrix[node][i]);
			}
		}
	}
	printf("\n");
}

int main()
{
	int i, node, a, b ,w, working = 1;
	char oper;
	graphType *G;
	G = (graphType*)malloc(sizeof(graphType));
	createGraph(G);

	for (i = 1; i <= 6; i++) {
		insertVertex(G, i);
	}
	insertEdge(G, 1, 6, 2);
	insertEdge(G, 1, 4, 1);
	insertEdge(G, 1, 3, 1);
	insertEdge(G, 1, 2, 1);
	insertEdge(G, 2, 3, 1);
	insertEdge(G, 2, 1, 1);
	insertEdge(G, 3, 5, 4);
	insertEdge(G, 3, 2, 1);
	insertEdge(G, 3, 1, 1);
	insertEdge(G, 4, 1, 1);
	insertEdge(G, 5, 6, 3);
	insertEdge(G, 5, 5, 4);
	insertEdge(G, 5, 3, 4);
	insertEdge(G, 6, 5, 3);
	insertEdge(G, 6, 1, 2);
	//print_adjMatrix(G);
	
	while (working) {
		scanf("%c", &oper);
		getchar();

		switch (oper) {
		case 'a':
			scanf("%d", &node);
			getchar();
			printNode(G, node);
			break;
		case 'm':
			scanf("%d %d %d", &a, &b, &w);
			getchar();
			if (a < G->n && b < G->n) {
				insertEdge(G, a, b, w);
				insertEdge(G, b, a, w);
			}
			else 
				printf("-1\n");		//exception
			break;
		case 'q':
			working = 0;
			break;
		}
		//print_adjMatrix(G);
	}
	return 0;
}