#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 20000 + 1;
const int INF = 987654321;

int V, E, Start;
vector<pair<int, int> > graph[MAX];


vector<int> Dijkstra(int start, int vertex) {
	//cost, vertex
	priority_queue <pair<int, int> > pq;
	pq.push({ 0, start });
	vector<int> dist(vertex, INF); //INF로 초기화
	dist[start] = 0;
	
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int curr = pq.top().second;
		pq.pop();

		if (dist[curr] < cost) continue;   
		for (int i = 0; i < graph[curr].size(); i++) {
			int neighb = graph[curr][i].first;
			int tmp_cost = cost + graph[curr][i].second;

			if (dist[neighb] > tmp_cost) {
				dist[neighb] = tmp_cost;
				pq.push({ -tmp_cost, neighb });
			}
		}

	}

	return dist;
}



int main() {
	
	

	//INPUT
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> V >> E >> Start;
	for (int i = 0; i < E; i++) {
		int from, to, w;
		cin >> from >> to >> w;
		graph[from].push_back({ to, w });
	}
	V++; //정점 1번부터
	//solve
	vector<int> result = Dijkstra(Start, V);
	
	//print result
	for (int i = 1; i < V; i++) {
		if (result[i] == INF) cout << "INF" << '\n';
		else cout << result[i] << '\n';
	}
	return 0;
}