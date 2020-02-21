#include <iostream>
using namespace std;
int N, cnt = 0;

void solve(int n, int from, int by, int to) {
	if (n == 1) cnt++;
	else {
		solve(n - 1, from, to, by);
		cnt++;
		solve(n - 1, by, from, to);
	}
}

int main() {
	cin >> N;
	solve(N, 1, 2, 3);
	cout << cnt << '\n';
	return 0;
}