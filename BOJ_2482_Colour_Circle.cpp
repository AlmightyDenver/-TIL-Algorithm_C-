#include <iostream>

using namespace std;
int N, K;
int memo[1001][1001];
int divi = 1000000003;

int DP(int x, int y) {
	if (memo[x][y] != 0) return memo[x][y];
	if (x > 1 && x >= (y * 2) && y >= 1) memo[x][y] = DP(x-1, y) + DP(x - 2, y - 1) % divi;
	return memo[x][y];
}


int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> K;
	
	for (int i = 1; i <= N; i++) {
		memo[i][1]= i;
		if (i % 2 == 0) memo[i][i / 2] = 2;
	}

	int ans = 0;
	if (K > N / 2) ans = 0;
	else if (K *2 == N) ans = 2;
	else ans = DP(N, K);
	cout << ans << '\n';

	return 0;
}