#include <iostream>
#include <queue>
using namespace std;
int K, W, H;
int map[200][200];
bool visit[200][200][30];
int dx[8] = { -2,-1,1,2,2,1,-1,-2 };
int dy[8] = { -1,-2,-2,-1,1,2,2,1 };
int fx[4] = { 0,0,1,-1 }; 
int fy[4] = { 1,-1,0,0 };

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> K;
	cin >> W >> H;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> map[i][j];
		}
	}

	queue<pair<pair<int, int>, pair<int, int> > > q;
	q.push(make_pair(make_pair(0, 0), make_pair(0, K)));
	visit[0][0][K] = true;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second.first;
		int k = q.front().second.second;
		q.pop();
		if (x == H - 1 && y == W - 1) {
			cout << cnt << '\n';
			return 0;
		}
		if (k > 0) {
			for (int i = 0; i < 8; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				
				if (!visit[nx][ny][k-1] && map[nx][ny] == 0 && nx >= 0 && ny >= 0 && nx < H && ny <W) {
					visit[nx][ny][k-1] = true;
					q.push(make_pair(make_pair(nx, ny), make_pair(cnt + 1, k - 1)));
				}
			}
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + fx[i];
			int ny = y + fy[i];

			if (nx == W - 1 && ny == H - 1) {
				cout << cnt + 1 << '\n';
				return 0;
			}
			//
			if (!visit[nx][ny][k] && map[nx][ny] == 0 && nx >= 0 && ny >= 0 && nx < H && ny < W) {
				visit[nx][ny][k] = true;
				q.push(make_pair(make_pair(nx, ny), make_pair(cnt + 1, k)));
			}
		}
	}
	cout << -1 << '\n';
	return 0;
}