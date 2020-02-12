#include <iostream>

using namespace std;
int N, M, r,c,d;
int map[50][50];
int dx[4] = { -1, 0, 1,0 }; //북 동 남 서
int dy[4] = { 0, 1,0,-1 };
int robot[3];
int cnt = 1;
int dir;

int turn_reverse(int dir) {
	//0,1,2,3 => 2,3,0,1
	int nd;
	if (dir == 0 || dir == 1) nd = dir + 2;
	else nd = dir - 2;
	return nd;
}
int turn_left(int dir) {
	//0,1,2,3 => 3,0,1,2
	int nd;
	if (dir == 0) nd = 3;
	else nd = dir - 1;
	return nd;
}


void solve(int turn_cnt, int dir) {
	if (turn_cnt >= 4 && dir == robot[2]) {
		//후진
		int nx = robot[0];
		int ny = robot[1];
		int k = 0;
		bool flag = false;
		//후진할 칸 nx. ny. 범위 내이고 벽 아니면
		while (nx >= 0 && ny >= 0 && nx < N && ny < M) {
			k++;
			nx = robot[0] + (-1) * k * dx[robot[2]];
			ny = robot[1] + (-1) * k * dy[robot[2]];
			if (map[nx][ny] != 1) {
				//후진해서 다음 이동할 칸 있는지 확인
				for (int i = 0; i < 4; i++) {
					int nnd = i;
					int nnx = nx + dx[nnd];
					int nny = ny + dy[nnd];
					//후진해서 청소할 곳 있으면
					if ((nnx >= 0 && nny >= 0 && nnx < N && nny < M) && map[nnx][nny] == 0) {
						robot[0] = nx;
						robot[1] = ny;
						turn_cnt = 0;
						solve(turn_cnt, robot[2]);
						flag = true;
						break;
					}
				}
				if (flag) break;
			}
			else break;
		}
		if (!flag) return;
		
	}


	int nd = turn_left(dir);
	int nx = robot[0] + dx[nd];
	int ny = robot[1] + dy[nd];

	if ((nx >= 0 && ny >= 0 && nx < N && ny < M) && map[nx][ny] == 0) {
		robot[0] = nx;
		robot[1] = ny;
		robot[2] = nd;
		//cout << nx << ' ' << ny << '\n';
		map[robot[0]][robot[1]] = 2;
		cnt++;
		turn_cnt = 0;
		solve(turn_cnt, nd);
	}
	else {
		turn_cnt++;
		solve(turn_cnt, nd);
	}
}


int main() {
	//input
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	//r, c, d
	cin >> robot[0] >> robot[1] >> robot[2];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	//시작이 벽이면
	if (map[robot[0]][robot[1]] == 1) {
		cout << 0 << '\n';
	}
	else {
		map[robot[0]][robot[1]] = 2;
		solve(0, robot[2]);
		cout << cnt << '\n';
	}
	return 0;
}