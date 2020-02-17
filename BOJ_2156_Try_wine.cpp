#include <iostream>
#include <algorithm>
using namespace std;
int n;
int wine[10000];
int memo[10000][3];

int main() {
	int ans = 0;

	//input
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> wine[i];
	}


	for (int i = 0; i < n; i++) {
		//이번에 안마심 => memo[i-1]에서 가장 큰 값 가져오기
		memo[i][0] = max(max(memo[i - 1][0], memo[i - 1][1]), memo[i - 1][2]);
		//전에 안먹고 이번에 마심
		memo[i][1] = memo[i-1][0] + wine[i];
		//전에 먹고 이번에도 마심
		memo[i][2] = memo[i - 1][1] + wine[i];

	}

	ans = max(max(memo[n-1][0], memo[n-1][1]), memo[n-1][2]);
	cout << ans << '\n';
	return 0;
}