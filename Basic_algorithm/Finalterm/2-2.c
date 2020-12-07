#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Edge
{
	int endpoint1, endpoint2;
	int weight;
}Edge;

typedef struct IncidentEdges
{
	int edge_num;
	struct IncidentEdges* next;

}IncidentEdges;

typedef struct Vertex
{
	int name;
	IncidentEdges* incidentedges;

}Vertex;

typedef struct Graph
{
	Vertex vertex[102];
	Edge edges[1002];
	int n;

}Graph;

void Initi(Graph* graph, int N);
void Input(Graph* graph, int vertex_index, int u, int v, int w);
void Swap(int* x, int* y);
IncidentEdges* makeEdge(int vertex_index, int w);
int Opposite(Graph* graph, int e);
int Origin(Graph* graph, int e);
void output(Graph* graph, int Distance[], int S);
void allPairsShotrestPaths(Graph* graph, int M);
int** D;

#define INFI 30000
#define MAX_WEI 20

int main()
{
	int N, M;
	int i;
	int u, v, w;
	Graph* graph;

	scanf("%d %d", &N, &M);

	D = (int**)calloc(N, sizeof(int*));
	for (i = 0; i < N; i++)
	{
		D[i] = (int*)calloc(N, sizeof(int));
	}

	graph = (Graph*)malloc(sizeof(Graph));
	memset(graph, 0, sizeof(Graph));

	Initi(graph, N);


	for (i = 0; i < M; i++)
	{
		scanf("%d %d %d", &u, &v, &w);
		D[u - 1][v - 1] = w;
		Input(graph, i, u - 1, v - 1, w);
	}

	allPairsShotrestPaths(graph, M);
	return 0;
}
void allPairsShotrestPaths(Graph* graph, int M)
{
	int i, j, k;

	for (i = 0; i < graph->n; i++)
	{
		for (j = 0; j < graph->n; j++)
		{
			if (D[i][j] == 0 && i != j)
				D[i][j] = INFI;
		}
	}
	for (k = 0; k < graph->n; k++)
	{
		for (i = 0; i < graph->n; i++)
		{
			for (j = 0; j < graph->n; j++)
			{
				if (D[i][j] > D[i][k] + D[k][j])
				{
					D[i][j] = D[i][k] + D[k][j];
				}
			}
		}
	}

	for (i = 0; i < graph->n; i++)
	{
		for (j = 0; j < graph->n; j++)
		{
			if (D[i][j] >= INFI - MAX_WEI && D[i][j] <= INFI)
				printf(" %c", '*');
			else
				printf(" %d", D[i][j]);
		}
		printf("\n");
	}
}
void output(Graph* graph, int Distance[], int S)
{
	int i;


	for (i = 0; i < graph->n; i++)
	{
		if (i != S - 1)
		{
			if (Distance[i] < 30000)
			{
				printf("%d %d\n", i + 1, Distance[i]);
			}

		}

	}
}
int Origin(Graph* graph, int e)
{
	return graph->edges[e].endpoint1;
}
int Opposite(Graph* graph, int e)
{
	return graph->edges[e].endpoint2;
}
void Input(Graph* graph, int vertex_index, int u, int v, int w)
{

	IncidentEdges* p;

	graph->edges[vertex_index].weight = w;
	graph->edges[vertex_index].endpoint1 = u;
	graph->edges[vertex_index].endpoint2 = v;


	// u
	if (graph->vertex[u].incidentedges == NULL)
	{
		p = makeEdge(vertex_index, w);
		graph->vertex[u].incidentedges = p;
	}
	else
	{
		p = graph->vertex[u].incidentedges;

		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = makeEdge(vertex_index, w);
	}
}
void Swap(int* x, int* y)
{
	int t;

	t = *x;
	*x = *y;
	*y = t;
}
void Initi(Graph* graph, int N)
{
	int i;

	for (i = 0; i < N; i++)
	{
		graph->vertex[i].name = i + 1;
	}

	graph->n = N;

	memset(graph->edges, -1, sizeof(Edge) * 1000);

}
IncidentEdges* makeEdge(int vertex_index, int w)
{
	IncidentEdges* p;

	p = (IncidentEdges*)malloc(sizeof(IncidentEdges));
	memset(p, 0, sizeof(IncidentEdges));

	p->edge_num = vertex_index;

	return p;

} 