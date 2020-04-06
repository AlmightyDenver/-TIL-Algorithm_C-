//union Find
#include <iostream>

using namespace std;
int N, M;
bool map[201][201];
int root[201];
int plan[1000];

int findd(int x) {
	if (root[x] == x) return x;
	else return root[x] = findd(root[x]);
}

void unionn(int x, int y) {
	x = findd(x);
	y = findd(y);

	if (x != y) root[y] = x;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < 201; i++) {
		root[i] = i;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
			if (map[i][j]) {
				unionn(i, j);
			}
		}
	}
	for (int i = 0; i < M; i++) {
		cin >> plan[i];
	}

	int num_root = findd(plan[0]);
	for (int i = 1; i < M; i++) {
		if (findd(plan[i]) != num_root) {
			cout << "NO" << '\n';
			return 0;
		}
	}
	cout << "YES" << '\n';


	return 0;
}