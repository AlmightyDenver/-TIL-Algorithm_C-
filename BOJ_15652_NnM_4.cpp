#include <iostream>

using namespace std;
int N, M;
int arr[9];

void dfs(const int& depth) {
	if (depth == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (i >= arr[depth - 1]) {
			arr[depth] = i;
			dfs(depth + 1);
		}
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		arr[0] = i;
		dfs(1);
	}

	return 0;
}