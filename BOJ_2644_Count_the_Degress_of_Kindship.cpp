#include <iostream>
#include <queue>

using namespace std;
int N, U, V, M;
int dist[101];
vector<int> adj[101];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };


int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	cin >> U >> V;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int ans = -1;
	queue<int> q;
	q.push(U);

	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		if (curr == V) {
			ans = dist[curr];
			break;
		}
		for (int i = 0; i < (int)adj[curr].size(); i++) {
			int next = adj[curr][i];
			if (dist[next] != 0) continue;
			q.push(next);
			dist[next] = dist[curr] + 1;
		}
	}

	cout << ans << '\n';

	return 0;
}
