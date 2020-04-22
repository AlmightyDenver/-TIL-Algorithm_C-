//#include <iostream>
//#include <vector>
//
//using namespace std;
//int N;
//int map[101][101];
//int dx[4] = { 1,0,-1,0 };
//int dy[4] = { 0,-1,0,1 };
//
//int main() {
//	ios::sync_with_stdio(0); cin.tie(0);
//	cin >> N;
//	for (int i = 0; i < N; i++) {
//		vector<int> curves; 
//		int x, y, d, g;
//		cin >> x >> y >> d >> g;
//		curves.push_back(d);
//		//curve
//		for (int j = 0; j < g; ++j) {
//			for (int k = curves.size() - 1; k >= 0; --k) {
//				curves.push_back((curves[k] + 1) % 4);
//			}
//		}
//	
//		//map[x][y] = true;
//		map[y][x] = 1;
//		for (int dir : curves) {
//			x += dx[dir];
//			y += dy[dir];
//			map[y][x] = 1;
//		}
//
//	}
//
//	
//	//count squre
//	int ans = 0;
//	for (int i = 0; i < 100; ++i) {
//		for (int j = 0; j < 100; ++j) {
//			if (map[i][j]==1 && map[i + 1][j]==1 && map[i][j + 1]==1 && map[i + 1][j + 1]==1) ans++;
//		}
//	}
//	cout << ans << '\n';
//
//	return 0;
//}