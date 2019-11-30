#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_VERTEX 101
#define FALSE 0
#define TRUE 1

typedef struct graphType {
	int n;
	int adjMatrix[MAX_VERTEX][MAX_VERTEX];
	int visited[MAX_VERTEX];
}graphType;

typedef int element;

typedef struct QNode {
	int data;
	struct QNode *link;
}QNode;

typedef struct {
	QNode *front, *rear;
}LQueueType;

LQueueType *createLinkedQueue() {
	LQueueType *LQ;
	LQ = (LQueueType*)malloc(sizeof(LQueueType));
	LQ->front = NULL;
	LQ->rear = NULL;
	return LQ;
}

int isEmpty(LQueueType *LQ) {
	if (LQ->front == NULL) {
		//printf("empty");
		return 1;
	}
	else return 0;
}

void enQueue(LQueueType* LQ, int item) {
	QNode *newNode = (QNode*)malloc(sizeof(QNode));
	newNode->data = item;
	newNode->link = NULL;
	if (LQ->front == NULL) {
		LQ->front = newNode;
		LQ->rear = newNode;
	}
	else {
		LQ->rear->link = newNode;
		LQ->rear = newNode;
	}
}

int deQueue(LQueueType *LQ) {
	QNode *old = LQ->front;
	int item;
	if (isEmpty(LQ)) return 0;
	else {
		item = old->data;
		LQ->front = LQ->front->link;
		if (LQ->front == NULL) {
			LQ->rear = NULL;
		}
		free(old);
		return item;
	}
}

void printQueue(LQueueType *LQ) {
	QNode *p = LQ->front;
	while (p->link != NULL) {
		printf(" %d", p->data);
		p = p->link;
	}
	printf("\n");
}

void createGraph(graphType *g) {
	int i, j;
	g->n = 1;
	for (i = 0; i < MAX_VERTEX; i++) {
		for (j = 0; j < MAX_VERTEX; j++) {
			g->adjMatrix[i][j] = 0;
		}
	}
}

void insertEdge(graphType* g, int u, int v) {
	if (u >= g->n || v >= g->n) {
		printf("-1\n");
		return;
	}
	g->adjMatrix[u][v] = TRUE;
}

void insertVertex(graphType *g, int v) {
	if (((g->n) + 1) > MAX_VERTEX) {
		printf("-1\n");
		return;
	}
	g->n++;
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

void BFS_adjList(graphType *g, int v) {
	int w, i;
	LQueueType *Q;
	Q = createLinkedQueue();
	g->visited[v] = TRUE;
	printf("%d\n", v);
	enQueue(Q, v);

	while (!isEmpty(Q)) {
		//printQueue(Q);
		v = deQueue(Q);

		for (i = 1; i <= g->n; i++) {
			w = g->adjMatrix[v][i];
			if (!g->visited[i] && w == TRUE) {
				g->visited[i] = TRUE;
				printf("%d\n", i);
				enQueue(Q, i);
			}
		}
	}
}

int main() {

	int i, n, m, s, u, v;
	graphType *G;

	scanf("%d %d %d", &n, &m, &s);

	G = (graphType*)malloc(sizeof(graphType));
	createGraph(G);

	for (i = 1; i <= n; i++) {
		insertVertex(G, i);
	}

	while (m--) {
		scanf("%d %d", &u, &v);
		insertEdge(G, u, v);
		insertEdge(G, v, u);
	}
	//print_adjMatrix(G);
	BFS_adjList(G, s);

	return 0;
}