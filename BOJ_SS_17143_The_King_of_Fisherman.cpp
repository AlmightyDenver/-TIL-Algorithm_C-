#include <iostream>

using namespace std;

int R, C, M;
int map[101][101];
int sharks[10201][5]; //x,y, 속력, 방향, 크기
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };
int ans = 0;
bool alive[10201];

void solve() {
	for (int col = 1; col <= C; col++) {
		for (int row = 1; row <= R; row++) {
			//잡았다면 무게 추가
			if (map[row][col] != 0) {
				ans += sharks[map[row][col]][4];
				alive[map[row][col]] = false;
				map[row][col] = 0;
				break;
			}
		}
		//1초후. 상어들 움직임
		for (int m = 1; m <= M; m++) {
			if (alive[m]) {
				int cx = sharks[m][0];
				int cy = sharks[m][1];
				//현재위치 + (속력 * 이동방향)
				int nx = cx + (sharks[m][2] * dx[sharks[m][3] - 1]);
				int ny = cy + (sharks[m][2] * dy[sharks[m][3] - 1]);

				//방향 바뀌는지
				int dir_change = 0;

				//범위 넘었으면
				while (nx < 1 || nx > R) {
					if (nx < 1) {
						nx = 1 - (-1 + nx);
						dir_change++;
					}
					if (nx > R){
						nx = R - (nx - R);
						dir_change++;
					}
				}
				while (ny < 1 || ny >C) {
					if (ny < 1) {
						ny = 1 - (-1 + ny);
						dir_change++;
					}
						if (ny > C) {
						ny = C - (ny - C);
						dir_change++;
					}
				}

				//자리 바뀌었으면 기존 자리 0으로
				if ((cx != nx || cy != ny) &&( map[cx][cy] == m)) map[cx][cy] = 0;

				//짝수이면 그대로. 홀수면 방향 바뀜
				if ((dir_change % 2) != 0) {
					// 1 / 3이면 +1해서 2, 4 . 아니면 빼주기. 여기선 dx,dy필요없으니 sharks[m][3] -1안함
					if (sharks[m][3] == 1 || sharks[m][3] == 3) sharks[m][3]++;
					else sharks[m][3]--;
				}

				//상어 잡아먹기

				//이미 있던애면 누가 큰지 비교
				if (map[nx][ny] != 0 && map[nx][ny] < m) {
					//새로운 애가 크면
					if (sharks[m][4] > sharks[map[nx][ny]][4]) {
						alive[map[nx][ny]] = false;//죽은애 삭제
						map[nx][ny] = m; // 자리 주인 바뀌고
						//정보 갱신
						sharks[m][0] = nx;
						sharks[m][1] = ny;
					}
					else alive[m] = false;
				}
				//아무도 없었으면
				else {
					map[nx][ny] = m;
					sharks[m][0] = nx;
					sharks[m][1] = ny;
				}

			}
		}
	}
	cout << ans << '\n';
}


int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> R >> C >> M;
	for (int m = 1; m <= M; m++) {
		for (int i = 0; i < 5; i++) {
			cin >> sharks[m][i];
		}
		map[sharks[m][0]][sharks[m][1]] = m;
		alive[m] = true;
	}
	solve();
	return 0;
}