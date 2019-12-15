#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_VERTEX 101

typedef struct QNode {
	int data;
	struct QNode *link;
}QNode;

typedef struct {
	QNode *front, *rear;
}LQueueType;

typedef struct listNode {
	int element;
	struct listNode *next;
}Node;

typedef struct graphNode {
	char name;
	int inDegree;
	Node *outEdges;
	Node *inEdges;
}graphNode;

typedef struct edgeNode {
	int origin;
	int destination;
}edgeNode;

typedef struct graphType {
	graphNode vertices[MAX_VERTEX];
	edgeNode edges[MAX_VERTEX];
}graphType;

int n, m;
int *topOrder;
int in[MAX_VERTEX];
graphType *G;
LQueueType *Q;

void initializeGraph(graphType* g);
LQueueType *createLinkedQueue();
int isEmpty(LQueueType *LQ);
void enQueue(LQueueType* LQ, int item);
int deQueue(LQueueType *LQ);
void buildGraph();

void insertVertex(char vName, int i) {
	G->vertices[i].name = vName;
	//G->vertices[i].outEdges = NULL;
	//G->vertices[i].inEdges = NULL;
	G->vertices[i].inDegree = 0;
}

int index(char vName) {										//draft complete!
	int i;

	for (i = 0; i < n; i++) {
		if (G->vertices[i].name == vName) {
			return i;
		}
	}
}

void addFirst(Node *H, int i) {
	Node *node = (Node*)malloc(sizeof(Node));
	node->element = i;
	node->next = H->next;
	H->next = node;

	return;
}

void insertDirectedEdge(char uName, char wName, int i) {	//draft complete
	int u = index(uName);
	int w = index(wName);

	G->edges[i].origin = u;
	G->edges[i].destination = w;

	addFirst(G->vertices[u].outEdges, i);
	addFirst(G->vertices[w].inEdges, i);

	G->vertices[w].inDegree++;

	return;
}

void topologicalSort() {

	int i, t, e;
	int u, w;
	Node *p;

	Q = createLinkedQueue();

	for (i = 0; i < n; i++) {
		in[i] = G->vertices[i].inDegree;
		if (in[i] == 0) {
			u = i;
			enQueue(Q, u);		//진입차수가 0인 정점들을 Q에 삽입
		}
	}

	t = 1;

	while (!isEmpty(Q)) {
		u = deQueue(Q);
		*(topOrder + t) = u;
		t = t + 1;

		for (p = G->vertices[u].outEdges->next; p != NULL; p = p->next) {
			e = p->element;
			w = G->edges[e].destination;
			in[w] = in[w] - 1;
			if (in[w] == 0) {
				enQueue(Q, w);
			}
		}
	}

	if (t <= n)
		*(topOrder + 0) = 0;
	else
		*(topOrder + 0) = 1;

	return;
}

void buildGraph() {											//draft complete!

	int i;
	char vName, uName, wName;

	initializeGraph(G);

	scanf("%d", &n);
	getchar();

	topOrder = (int*)malloc(sizeof(int)*(n + 1));

	for (i = 0; i < n; i++) {
		scanf("%c", &vName);
		getchar();
		insertVertex(vName, i);
	}

	scanf("%d", &m);
	getchar();

	for (i = 0; i < m; i++) {
		scanf("%c %c", &uName, &wName);
		getchar();
		insertDirectedEdge(uName, wName, i);
	}

	return;
}


int main() {

	int i;

	LQueueType *Q;
	G = (graphType*)malloc(sizeof(graphType));

	buildGraph();

	topologicalSort();

	if (*(topOrder + 0) == 0) {
		printf("0\n");
	}
	else {
		for (i = 1; i <= n; i++) {
			printf("%c ", G->vertices[topOrder[i]].name);
		}
		printf("\n");
	}

	return 0;
}

void initializeGraph(graphType* g) {
	int v;
	for (v = 0; v <= MAX_VERTEX; v++) {
		g->vertices[v].inEdges = (Node*)malloc(sizeof(Node));
		g->vertices[v].inEdges->next = NULL;
		g->vertices[v].outEdges = (Node*)malloc(sizeof(Node));
		g->vertices[v].outEdges->next = NULL;
	}
}

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

