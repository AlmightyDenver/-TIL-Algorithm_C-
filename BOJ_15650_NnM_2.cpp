#include <iostream>

using namespace std;
int N, M;
bool visit[9];
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
		if (!visit[i] && i > arr[depth -1]) {
			visit[i] = true;
			arr[depth] = i;
			dfs(depth + 1);
			
			visit[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		visit[i] = true;
		arr[0] = i;
		dfs(1);
		visit[i] = false;

	}
}