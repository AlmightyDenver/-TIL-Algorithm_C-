#include <iostream>
#include <memory.h>
#include <algorithm>

using namespace std;
int dist[16][16];
int memo[16][1 << 16];
int N;

int TSP(int curr, int visit) {
	int& ret = memo[curr][visit];
	if (ret != -1) return ret;

	if (visit == (1 << N) - 1) {
		if (dist[curr][0] != 0) return dist[curr][0];
	}
	
		ret = 1987654321;
	for (int i = 0; i < N; i++) {
		//방문 했거나 경로없으면 
		if (visit & (1 << i) || dist[curr][i] == 0)continue;
		ret = min(ret, TSP(i, visit | (1 << i)) + dist[curr][i]);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0);  cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> dist[i][j];
		}
	}

	memset(memo, -1 , sizeof(memo));
	cout << TSP(0, 1) << '\n';
	return 0;
}