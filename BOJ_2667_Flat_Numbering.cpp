//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//int N;
//int map[25][25];
//bool visit[25][25] = { false, };
//vector<int> counts;
//int dx[4] = { 0,0,1,-1 };
//int dy[4] = { 1,-1,0,0 };
//
//int DFS(int y, int x) {
//	int cnt = 1;
//	visit[y][x] = true;
//	if (map[y][x] == 1) {
//		for (int i = 0; i < 4; i++) {
//			int ny = y + dy[i];
//			int nx = x + dx[i];
//			if (map[ny][nx] == 0 || visit[ny][nx] || nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
//			cnt += DFS(ny, nx);
//		}
//	}
//	return cnt;
//}
//
//
//int main() {
//	//input
//	ios::sync_with_stdio(0); cin.tie(0);
//	cin >> N;
//	for (int i = 0; i < N; i++) {
//		string Inp;
//		cin >> Inp;
//		for (int j = 0; j < Inp.length(); j++)
//		{
//			int Temp = Inp[j] - '0';
//			map[i][j] = Temp;
//		}
//	}
//
//	int flat = 0;
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			if (map[i][j] == 0 || visit[i][j]) continue;
//			flat++;
//			counts.push_back(DFS(i, j));
//		}
//	}
//	sort(counts.begin(), counts.end());
//	cout << flat << '\n';
//	for (int i = 0; i < counts.size(); i++) {
//		cout << counts[i] << '\n';
//	}
//	return 0;
//}