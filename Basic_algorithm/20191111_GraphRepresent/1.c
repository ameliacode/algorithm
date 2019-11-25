#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTEX 21

int mFlag = 0;

typedef struct vertex {
	int v, weight;
}Vertex;

typedef struct graphNode {
	Vertex vertex;
	struct graphNode *link;
}graphNode;

typedef struct graphType {
	int n;
	graphNode *adjList_H[MAX_VERTEX];
}graphType;

void createGraph(graphType *g) {
	int v;
	g->n = 1;
	for (v = 0; v < MAX_VERTEX; v++) {
		g->adjList_H[v] = NULL;
	}
}

graphNode* searchVertex(graphType *g, int u, int v) {
	graphNode *p = g->adjList_H[u];
	while (p) {
		if (p->vertex.v == v) {
			return p;
		}
		p = p->link;
	}
	return NULL;
}

void insertVertex(graphType* g, int v) {
	if (((g->n) + 1) > MAX_VERTEX) {
		printf("-1\n");
		return;
	}
	g->n++;
}

void insertEdge(graphType* g, int u, int v, int w) {
	graphNode *node, *temp;

	if (u >= g->n || v >= g->n) {
		printf("-1\n");
		return;
	}

	node = (graphNode*)malloc(sizeof(graphNode));
	node->vertex.v = v;
	node->vertex.weight = w;
	node->link = NULL;

	if (g->adjList_H[u] == NULL) {
		g->adjList_H[u] = node;
	}
	else {
		temp = g->adjList_H[u];
		while (temp->link != NULL) {
			temp = temp->link;
		}
		temp->link = node;
	}
}

void print_adjList(graphType *g) {
	int i;
	graphNode *p;
	for (i = 1; i <= 6; i++) {
		p = g->adjList_H[i];
		while (p) {
			printf(" %d", p->vertex.v);
			p = p->link;
		}
		printf("\n");
	}
}

void A(graphType *g, int v) {
	graphNode *p;
	p = g->adjList_H[v];
	if (p == NULL) {
		printf("-1\n");
		return;
	}
	while (p) {
		printf(" %d %d", p->vertex.v, p->vertex.weight);
		p = p->link;
	}
	printf("\n");
}

void M(graphType *g, int a, int b, int w) {
	graphNode *node, *temp, *p, *q;
	temp = searchVertex(g, a, b);							//temp = old
	if (w != 0) {											//Insert node
		if (temp != NULL) {									//if node exists, change weight
			temp->vertex.weight = w;
		}
		else {												//if not, create new node
			node = (graphNode*)malloc(sizeof(graphNode));
			node->vertex.v = b;
			node->vertex.weight = w;
			node->link = NULL;

			p = g->adjList_H[a];
			q = p;											//q=pre node of p
			while (p != NULL) {
				if (p->vertex.v > b) {						//q node p
					break;
				}
				q = p;
				p = p->link;
			}

			if (p != g->adjList_H[a]) {						//if searched node isn't the first node,
				if (q->link != NULL) node->link = q->link;		//add middle node
				q->link = node;								//add middle&last node
			}
			else {											//add first node
				node->link = g->adjList_H[a];
				g->adjList_H[a] = node;
			}
		}
	}
	else {													//Delete node
		if (temp == NULL) {									//if node doesn't exist print -1
			mFlag = 1;
			return;
		}
		else {												//if it does,
			p = g->adjList_H[a];

			if (p == temp) {								//delete first node
				g->adjList_H[a] = p->link;
			}
			else {
				q = p;
				while (p->link != NULL) {
					if (p->link->vertex.v > b) {
						break;
					}
					q = p;
					p = p->link;
				}

				if (p->link == NULL) {						//delete last node				
					q->link = NULL;
				}
				else {										//delete middle node
					q->link = p->link;
					p->link = NULL;
				}
			}
			free(p);
		}
	}
}

int main() {

	int node, a, b, w, i;
	int working = 1;
	char oper;
	graphType *G;
	G = (graphType*)malloc(sizeof(graphType));
	createGraph(G);

	for (i = 1; i <= 6; i++) {
		insertVertex(G, i);
	}

	insertEdge(G, 1, 2, 1);
	insertEdge(G, 1, 3, 1);
	insertEdge(G, 1, 4, 1);
	insertEdge(G, 1, 6, 2);
	insertEdge(G, 2, 1, 1);
	insertEdge(G, 2, 3, 1);
	insertEdge(G, 3, 1, 1);
	insertEdge(G, 3, 2, 1);
	insertEdge(G, 3, 5, 4);
	insertEdge(G, 4, 1, 1);
	insertEdge(G, 5, 3, 4);
	insertEdge(G, 5, 5, 4);
	insertEdge(G, 5, 6, 3);
	insertEdge(G, 6, 1, 2);
	insertEdge(G, 6, 5, 3);
	//print_adjList(G);

	while (working) {
		scanf("%c", &oper);
		getchar();
		switch (oper) {
		case 'a':
			scanf("%d", &node);
			getchar();	
			if (node >= G->n)										//out of vertex range
				printf("-1\n");	
			else
				A(G, node);
			break;
		case 'm':
			scanf("%d %d %d", &a, &b, &w);
			getchar();
			if (a >= G->n || b >= G->n || a == 0 || b == 0)			//out of vertex range
				printf("-1\n");
			else {
				if (a != b) {										//point other
					M(G, a, b, w);
					M(G, b, a, w);
				}
				else if (a == b) {									//point self
					M(G, a, b, w);
				}
				if (mFlag == 1) {
					printf("-1\n");
					mFlag = 0;
				}
			}
			break;
		case 'q':
			working = 0;
			break;
		}
	}
	return 0;
}