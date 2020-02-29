#include <iostream>
#include <string.h> //memset
using namespace std;
int N, M;
int map[300][300];
bool visit[300][300] = { false, };
int dx[4] = { 0,0,1,-1 };
int dy[4] = {1, -1, 0, 0};


void dfs(int y, int x) {
	visit[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (map[ny][nx] < 0) map[ny][nx] = 0;
		if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
		if (map[ny][nx] == 0 || visit[ny][nx]) continue;
		dfs(ny, nx);
	}
}



void melt(int y, int x) {
	int water = 0; //4�濡 �ٴ� ����
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
		if (map[ny][nx] == 0) water += 1;
	}

	int after_year = map[y][x] - water;
	//�����ִ� -1ó��. ���߿� ���� ���� ���� 0���� �ٲ�
	if (after_year == 0)map[y][x] = -1;
	else map[y][x] -= water;
}

int main() {	
	//input
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}


	//solve
	int ans = 0;
	while (true) {
		ans += 1;
		memset(visit, 0, sizeof(visit));
		int cnt_ice = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] != 0) melt(i, j);
				if (map[i][j] > 0) cnt_ice += 1;
			}
		}

		//�� ���������� �и� �ȵǸ� 0 ���
		if (cnt_ice == 0) {
			cout << 0 << '\n';
			return 0;
		}

		//���� ���� ����
		int cnt_iceBerg = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				//��Ƽ� 0�Ǿ -1�� ������ �� 0���� �ٲ��ֱ�
				if (map[i][j] < 0) map[i][j] = 0;
				if (map[i][j] == 0 || visit[i][j]) continue;
				cnt_iceBerg += 1;
				dfs(i, j);
			}
		}
		if (cnt_iceBerg > 1) {
			cout << ans << '\n';
			return 0;

		}
	}	
}