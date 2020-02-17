#include <iostream>
#include <algorithm>
using namespace std;
int N;
int step[300];
int memo[300][3];



int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> step[i];
	}

	for (int i = 0; i < N; i++) {
		memo[i][0] = max(memo[i - 1][1], memo[i - 1][2]);
		memo[i][1] = memo[i - 1][0] + step[i];
		memo[i][2] = memo[i - 1][1] + step[i];
	}
	int ans = max(memo[N - 1][1], memo[N - 1][2]);
	cout << ans << '\n';
	return 0;
}