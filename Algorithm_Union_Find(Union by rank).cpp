//Union find : Detect Cycle in an Undirected Gragh
//O(logn)
#include <iostream>

using namespace std;

struct Edge {
	int src, dest;
};

struct Graph {
	int V, E;
	struct Edge* edge;
};

struct subset {
	int parent;
	int rank;
};

struct Graph* createGraph(int V, int E) {
	struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
	graph->V = V;
	graph->E = E;

	graph->edge = (struct Edge*) malloc(graph->E * sizeof(Edge));

	return graph;
}


int findd(struct subset subsets[], int i) {
	if (subsets[i].parent != i) subsets[i].parent = findd(subsets, subsets[i].parent);
	return subsets[i].parent;
}

void Unionn(struct subset subsets[], int x, int y) {
	int xroot = findd(subsets, x);
	int yroot = findd(subsets, y);

	//깊이 얕은를 높은애한테 저장
	if (subsets[xroot].rank < subsets[yroot].rank)subsets[xroot].parent = yroot;
	else if (subsets[xroot].rank > subsets[yroot].rank)subsets[yroot].parent = xroot;
	//같으면 y를 x에 붙이고 x rank ++
	else {
		subsets[yroot].parent = xroot;
		subsets[xroot].rank++;
	}
}


bool isCycle(Graph* graph) {

	int V = graph->V;
	int E = graph->E;

	struct subset* subsets = (struct subset*) malloc(V * sizeof(struct subset));
	for (int v = 0; v < V; ++v) {
		subsets[v].parent = v;
		subsets[v].rank = 0;
	}


	for (int e = 0; e < E; ++e) {
		int x = findd(subsets, graph->edge[e].src);
		int y = findd(subsets, graph->edge[e].dest);
		if (x == y) return 1;
		Unionn(subsets, x, y);
	}
	return 0;
}


int main() {
	//number of vertex = 3, numberof Edge = 3
	// 0
	//| \
	//1--2
	int V = 3, E = 3;
	struct Graph* graph = createGraph(V, E);

	//add edge
	graph->edge[0].src = 0;
	graph->edge[0].dest = 1;
	graph->edge[1].src = 1;
	graph->edge[1].dest = 2;
	graph->edge[2].src = 0;
	graph->edge[2].dest = 2;

	if (isCycle(graph)) cout << "Graph contains cycle";
	else cout << "Graph dosn;t contain cycle";

	return 0;
}