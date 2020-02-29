#include <iostream>
bool dist[1001];
using namespace std;
int N, M;
int cost_map[102][102];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;


	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		cost_map[a][b] = 1;
		cost_map[b][a] = 1;
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <=N; i++) {
			for (int j = 1; j <= N; j++) {
				if (i == j) continue;
				else if(cost_map[i][k] != 0 && cost_map[k][j] != 0){
					if (cost_map[i][j] == 0) cost_map[i][j] = cost_map[i][k] + cost_map[k][j];
					else {
						int tmp = cost_map[i][k] + cost_map[k][j];
						cost_map[i][j] = cost_map[i][j] < tmp ? cost_map[i][j] : tmp;
					}
				} 
			}
		}
	}

	int mini = 2e9;
	int ans_idx;

	for (int i = 1; i <= N; i++) {
		int tmp = 0;
		for (int j = 1; j <= N; j++) {
			tmp += cost_map[i][j];
		}
		if (tmp < mini) {
			mini = tmp;
			ans_idx = i;
		}
	}

	cout << ans_idx << '\n';
	return 0;
}