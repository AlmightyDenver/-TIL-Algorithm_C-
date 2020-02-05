#include <iostream>

using namespace std;

int R, C, M;
int map[101][101];
int sharks[10201][5]; //x,y, �ӷ�, ����, ũ��
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };
int ans = 0;
bool alive[10201];

void solve() {
	for (int col = 1; col <= C; col++) {
		for (int row = 1; row <= R; row++) {
			//��Ҵٸ� ���� �߰�
			if (map[row][col] != 0) {
				ans += sharks[map[row][col]][4];
				alive[map[row][col]] = false;
				map[row][col] = 0;
				break;
			}
		}
		//1����. ���� ������
		for (int m = 1; m <= M; m++) {
			if (alive[m]) {
				int cx = sharks[m][0];
				int cy = sharks[m][1];
				//������ġ + (�ӷ� * �̵�����)
				int nx = cx + (sharks[m][2] * dx[sharks[m][3] - 1]);
				int ny = cy + (sharks[m][2] * dy[sharks[m][3] - 1]);

				//���� �ٲ����
				int dir_change = 0;

				//���� �Ѿ�����
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

				//�ڸ� �ٲ������ ���� �ڸ� 0����
				if ((cx != nx || cy != ny) &&( map[cx][cy] == m)) map[cx][cy] = 0;

				//¦���̸� �״��. Ȧ���� ���� �ٲ�
				if ((dir_change % 2) != 0) {
					// 1 / 3�̸� +1�ؼ� 2, 4 . �ƴϸ� ���ֱ�. ���⼱ dx,dy�ʿ������ sharks[m][3] -1����
					if (sharks[m][3] == 1 || sharks[m][3] == 3) sharks[m][3]++;
					else sharks[m][3]--;
				}

				//��� ��ƸԱ�

				//�̹� �ִ��ָ� ���� ū�� ��
				if (map[nx][ny] != 0 && map[nx][ny] < m) {
					//���ο� �ְ� ũ��
					if (sharks[m][4] > sharks[map[nx][ny]][4]) {
						alive[map[nx][ny]] = false;//������ ����
						map[nx][ny] = m; // �ڸ� ���� �ٲ��
						//���� ����
						sharks[m][0] = nx;
						sharks[m][1] = ny;
					}
					else alive[m] = false;
				}
				//�ƹ��� ��������
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