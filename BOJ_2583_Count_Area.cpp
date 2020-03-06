#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int M, N, K;
bool map[100][100];
bool visit[100][100] = { false, };
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
vector<int> vec;

int DFS(int y, int x) {
	int area = 1;
	visit[y][x] = true;
	if (map[y][x] == 0) {
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (map[ny][nx] == 1 || visit[ny][nx]) continue;
			area += DFS(ny, nx);
		}
	}
	return area;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> M >> N >> K;
	for (int i = 0; i < K; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = y1; i < y2; i++) {
			for (int j = x1; j < x2; j++) {
				map[i][j] = true;
			}
		}
	}
	
	int cnt_area = 0;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 1 || visit[i][j])continue;
			cnt_area++;
			vec.push_back(DFS(i, j));
		}
	}


	
	sort(vec.begin(), vec.end());
	cout << cnt_area << '\n';
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << ' ';
	}
	return 0;
}