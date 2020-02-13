#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int map[50][50];
int colour[50][50];

int check(int x, int y) {
	int cnt1 = 0;
	int cnt2 = 0;
	for (int i = x; i < x + 8; i++) {
		for (int j = y; j < y + 8; j++) {
			if (colour[i][j] == 1) cnt1++;
			else cnt2++;
		}
	}
	cout << x << ' ' << y << " : ";
	cout << cnt1 << ' ' << cnt2 << " sum : "<< cnt1 + cnt2 << '\n';
	return min(cnt1, cnt2);
}

int solve() {
	int mini = 2e9;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			//È¦¼öÁÙ È¦¼öÄ­, Â¦ÁÙ Â¦Ä­
			if ((i % 2 != 0 && j%2 != 0) || (i % 2 == 0 && j % 2 == 0)) {
				//½ÃÀÛ »ö °ú °°¾Æ¾ßÇÔ. °°Áö ¾ÊÀ¸¸é 1, °°À¸¸é 0
				if (map[i][j] != map[0][0]) colour[i][j] = 1;
				else colour[i][j] = 0;
			}
			else {
				if (map[i][j] == map[0][0]) colour[i][j] = 1;
				else colour[i][j] = 0;
			}
		}
	}
	for (int i = 0; i <= N - 8; i++) {
		for (int j = 0; j <= M - 8; j++) {
			//cout << i << ' ' << j << ' ';
			//cout << check(i, j) << '\n';
			mini = min(mini, check(i, j));
		}
	}
	return mini;
}

int main() {
	//input
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char colour;
			cin >> colour;
			if (colour == 'B') map[i][j] = 0;
			else map[i][j] = 1;
		}
	}

	cout << solve() << '\n';

	return 0;
}