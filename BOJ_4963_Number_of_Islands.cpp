#include <iostream>
#include <memory.h>

using namespace std;
int w, h;
int map[50][50];
int dx[8] = { 0,0,1,-1,-1 ,-1,1,1};
int dy[8] = { 1,-1,0,0 ,-1,1,-1,1};
bool visit[50][50] = { false, };
int ans = 0;



void DFS(int y, int x) {
	visit[y][x] = true;
	if (map[y][x] == 1) {
		for (int i = 0; i < 8; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (nx < 0 || ny < 0 || nx >= w || ny >= h || visit[ny][nx] || map[ny][nx] == 0) continue;
			DFS(ny, nx);
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	while (true) {
		cin >> w >> h;
		if (w == 0 && h == 0) break;
		memset(map, 0, sizeof(map));
		memset(visit, false, sizeof(visit));
		ans = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
			}
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				//cout << map[i][j] << ' ';
				if (map[i][j] == 1 && !visit[i][j]) {
					ans++;
					DFS(i, j);
				}
			}
			//cout << '\n';
		}
		cout << ans << '\n';
		
	}
	return 0;
}