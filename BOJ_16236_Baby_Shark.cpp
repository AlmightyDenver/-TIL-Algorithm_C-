#include <iostream>
#include <queue>
#include <memory.h> //memset

using namespace std;
int N;
int map[20][20]; 
int check[20][20];
int cy, cx, my, mx, md;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int shark_size = 2, ate = 0, dist = 0;

void init() {
	md = 2e9;
	my = 21;
	mx = 21;
	memset(check, -1, sizeof(check));
}

void BFS(int y, int x) {
	queue<pair<int, int> > q;
	q.push(make_pair(y, x));
	check[y][x] = 0;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || nx >= N || ny >= N || check[ny][nx] != -1 || map[ny][nx] > shark_size) continue;
		
			//이동거리 저장
			check[ny][nx] = check[y][x] + 1;
			//먹이 발견
			if (map[ny][nx] < shark_size && map[ny][nx] != 0) {
				if (check[ny][nx] < md) {
					md = check[ny][nx];
					my = ny;
					mx = nx;
				}
				else if (check[ny][nx] == md) {
					//위 먼저
					if (my > ny) {
						my = ny;
						mx = nx;
					}
					//왼 먼저
					else if (my == ny) {
						if (mx > nx) {
							my = ny;
							mx = nx;
						}
					}
				}
			}
			q.push(make_pair(ny, nx));
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				cy = i;
				cx = j;
				map[i][j] = 0;
			}
		}
	}

	while (true) {
		init();
		BFS(cy, cx);
		//물고기 찾았으면
		if (my != 21 && mx != 21) {
			map[my][mx] = 0;
			dist += check[my][mx];
			ate++;
			if (ate == shark_size) {
				shark_size++;
				ate = 0;
			}
			cy = my;
			cx = mx;
		}
		//없으면
		else break;
	}

	cout << dist << '\n';
	return 0;
}