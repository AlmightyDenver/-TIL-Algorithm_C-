#include <iostream>
using namespace std;
int N;
int memo[1000000];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	int answer = 0;

	memo[0] = 0;
	memo[1] = 1;
	memo[2] = 2;
	memo[3] = 3;
	for (int i = 4; i <= N; i++) {
		memo[i] = memo[i - 1] + memo[i - 2];
		memo[i] %= 15746;
	}
	answer = memo[N];
	cout << answer << '\n';
	return 0;
}