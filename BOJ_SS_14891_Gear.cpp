#include <iostream>

using namespace std;
int gear[4][8];
int turn[100][2];
bool dirs[3];
int K;

void turn_gear(int gr, int dir) {
	if (dir == -1) {
		int tmp = gear[gr][0];
		for (int i = 0; i < 7; i++){
			gear[gr][i] = gear[gr][i+1];
		}
		gear[gr][7] = tmp;
	}
	else {
		int tmp = gear[gr][7];
		for (int i = 6; i >= 0; i--) {
			gear[gr][i] = gear[gr][i - 1];
		}
		gear[gr][0] = tmp;
	}
}



void solve() {
	for (int i = 0; i < K; i++) {
		int currg = turn[i][0];
		int currdir = turn[i][1];
		int nextg = turn[i][0] + 1;
		int prevg = turn[i][0] - 1;

		while (true) {
			if (nextg > 4) break;
			if (gear[nextg][6] == gear[currg][2]) break;
			currdir *= (-1);
			turn_gear(nextg, currdir);
			nextg += 1;
		}

		currdir = turn[i][1];
		while (true) {
			if (prevg <= 0) break;
			if (gear[currg][6] == gear[prevg][2]) break;
			currdir *= (-1);
			turn_gear(prevg, currdir);
			nextg -= 1;
		}
		turn_gear(currg, turn[i][1]);
	}



}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> gear[i][j];
		}
	}

	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> turn[i][0] >> turn[i][1];
	}

	solve();

	int ans = 0;
	ans += gear[0][0];
	ans += gear[1][0] * 2;
	ans += gear[2][0] * 4;
	ans += gear[3][0] * 8;
	cout << ans << '\n';


	return 0;
}