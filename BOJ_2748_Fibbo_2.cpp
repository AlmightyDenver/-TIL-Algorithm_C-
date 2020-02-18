#include <iostream>

using namespace std;
long long memo[90];
int N;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N;

	memo[0] = 0;
	memo[1] = 1;
	for (int i = 2; i <= N; i++) {
		memo[i] = memo[i - 1] + memo[i - 2];
	}

	cout << memo[N] << '\n';
	return 0;

}