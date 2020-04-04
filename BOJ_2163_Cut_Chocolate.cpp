#include <iostream>

using namespace std;
int N, M;
int memo[302];

int DP(int y) {
	if (y > 0) memo[y] = DP(y - 1) + memo[1] + 1;
	return memo[y];
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N + 1; i++) memo[i] = -1;
	memo[1] = M - 1;
	cout << DP(N) << '\n';

	return 0;
}