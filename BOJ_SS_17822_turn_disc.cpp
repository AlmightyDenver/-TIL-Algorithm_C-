#include <iostream>
#include <queue>
using namespace std;
int N, M, T, x, d, k;
queue<pair<int, int> > q;
int map[51][51];
int* turn = new int[N];
int dx[2] = { 0,1 };
int dy[2] = { 1,0 };
bool flag = false;

void erase(int i, int j, int n) {
	if (map[i][j] != 0) {

		for (int d = 0; d < 2; d++) {
			int my = 0;
			if (d == 1) my = turn[i] - turn[i + 1];
			int nx = i + dx[d];
			int ny = j + dy[d] + my;

			if (nx == N) continue;
			if (ny == M) ny = 0;
			else if (ny < 0) ny = M - ny;

			if (map[nx][ny] == n) {
				erase(nx, ny, map[i][j]);
				map[i][j] = 0;
				map[nx][ny] = 0;
				flag = true;
			}
		}
	}
}

void solve() {
	//움직인 칸 수 turn 에 저장
	for (int i = 0; i < M; i++) {
		if ((i + 1) % x == 0) turn[i] += k;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] != 0) erase(i, j, map[i][j]);
		}
	}

	//지울거 없으면 평균값 +-
	if (!flag) {
		//평균 n 구하기
		double n = 0;
		double cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] != 0) {
					n += map[i][j];
					cnt++;
				}
			}
		}
		n /= cnt;
		//+-
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] != 0 && map[i][j] > n) map[i][j]--;
				else if (map[i][j] != 0 && map[i][j] < n) map[i][j]++;
			}
		}
	}
}

int main() {
	int ans = 0;
	cin >> N >> M >> T;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < M; i++) {
		turn[i] = 0;
	}

	for (int i = 0; i < T; i++) {
		cin >> x >> d >> k;
		//시계 방향으로 바꾸기
		if (d == 1) k = M - k;
		flag = false;
		solve();

	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] != 0) ans += map[i][j];
		}
	}
	cout << ans << '\n';
	return 0;
}