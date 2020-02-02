#include <iostream>
#include <string>

using namespace std;
int r, c;
//A : 1, B : 2 ... Z : 26
int map[21][21];
bool visit[27];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int maxi = 1;

void dfs(int x, int y, int depth) {

	visit[map[x][y]] = true;

	if (depth > maxi) maxi = depth;

	for (int d = 0; d < 4; d++) {
		int nx = x + dx[d];
		int ny = y + dy[d];
		if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
		if (!visit[map[nx][ny]]) dfs(nx, ny, depth + 1);
	}
	visit[map[x][y]] = false;
}

int main() {
	//input
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < c; j++) {
			map[i][j] = int(s[j]) -64;
		}		
	}
	dfs(0,0, 1);
	cout << maxi << '\n';
	return 0;
}