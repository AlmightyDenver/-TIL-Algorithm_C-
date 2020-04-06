//Union find : Detect Cycle in an Undirected Gragh
O(n)

#include <iostream>

using namespace std;

class Edge {
public :
	int src, dest;
};

class Graph {
public :
	int V, E;
	Edge* edge;
};

Graph* createGraph(int V, int E) {
	Graph* graph = new Graph();
	graph->V = V;
	graph->E = E;

	graph->edge = new Edge[graph->E * sizeof(Edge)];

	return graph;
}

int findd(int parent[], int i) {
	if(parent[i] == -1) return i;
	return findd(parent, parent[i]);
}

void Unionn(int parent[], int x, int y) {
	int xset = findd(parent, x);
	int yset = findd(parent, y);
	if (xset != yset) parent[xset] = yset;
}


bool isCycle(Graph* graph) {
	int* parent = new int[graph->V * sizeof(int)];
	memset(parent, 0 - 1, sizeof(int) * graph->V);

	for (int i = 0; i < graph->E; ++i) {
		int x = findd(parent, graph->edge[i].src);
		int y = findd(parent, graph->edge[i].dest);

		if (x == y) return true;

		Unionn(parent, x, y);
	}
	return false;
}

int main() {
	//number of vertex = 3, numberof Edge = 3
	// 0
	//| \
	//1--2
	int V = 3, E = 3;
	Graph* graph = createGraph(V, E);

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