#include <iostream>

using namespace std;
int N;
int map[101][101];
bool visit[101][101];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };


void DFS(int y, int x, int col) {
	visit[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (nx < 0 || ny < 0 || nx >= N || ny >= N || map[ny][nx] != col || visit[ny][nx]) continue;
		DFS(ny, nx, col);
	}
}

int main() {
	//INPUT
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char col;
			cin >> col;
			if (col == 'R') map[i][j] = 0;
			else if (col == 'G') map[i][j] = 1;
			else map[i][j] = 2;
		}
	}

	//Solve
	bool flag = false;
	while (true) {
		//init visit array
		if (flag) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					visit[i][j] = false;
					if (flag && map[i][j] == 1) map[i][j] = 0;
				}
			}
		}

		int cnt_area = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				int col;
				if (!visit[i][j]) {
					col = map[i][j];
					cnt_area++;
					DFS(i, j, col);
				}
			}
		}
		cout << cnt_area << ' ';
		if (flag) break;
		else flag = true;
	}

	return 0;
}