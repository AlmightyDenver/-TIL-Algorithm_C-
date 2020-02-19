#include <iostream>

using namespace std;
int N;
long long memo[101][11];
const int MAX = 1000000000;

int  main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for (int i = 1; i <= 9; i++) {
		memo[1][i] = 1;
	}

	for (int i = 2; i <= N; i++) {
		memo[i][0] = memo[i - 1][1];
		memo[i][9] = memo[i - 1][8];
		for (int j = 1; j < 9; j++) {
			memo[i][j] = ((memo[i - 1][j - 1] + memo[i-1][j+1]) % MAX);
		}
	}

	long long ans = 0;
	for (int i = 0; i <= 9; i++) {
		ans += memo[N][i];
	}
	cout << ans % MAX << '\n';

	return 0;
}