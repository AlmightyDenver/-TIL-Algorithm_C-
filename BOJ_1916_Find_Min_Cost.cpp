#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int MAX = 1000 + 1;
const int INF = 987654321;
int N, M, start, endd;
vector<pair<int, int> > graph[MAX];

vector<int> Dijkstra(int start) {
	vector<int> dist(N, INF);
	dist[start] = 0;

	priority_queue<pair<int, int> > pq;
	pq.push({ 0, start });

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
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		graph[from].push_back({ to, cost });
	}
	N++;
	cin >> start >> endd;


	vector<int> result = Dijkstra(start);
	cout << result[endd] << '\n';

	return 0;
}