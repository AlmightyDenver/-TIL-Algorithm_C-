//#include <iostream>
//
//using namespace std;
//int N, len;
//int map[200][100];
//
//int main() {
//	ios::sync_with_stdio(0); cin.tie(0);
//	cin >> N >> len;
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			cin >> map[i][j];
//		}
//	}
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			map[i + N][j] = map[j][i];
//		}
//	}
//
//	int ans = 0;
//	for (int i = 0; i < N*2; i++) {
//		int flat = 1;
//		for (int j = 0; j < N-1; j++) {
//			if (map[i][j] == map[i][j + 1]) flat++;
//			//내리막길
//			else if (map[i][j] - 1 == map[i][j + 1] && flat >= 0) flat = -len + 1;
//			//오를막길
//			else if (map[i][j] + 1 == map[i][j + 1] && flat >= len) flat = 1;
//			else {
//				flat = -1;
//				break;
//			}
//		}
//		if (flat >= 0) ans++;
//	}
//
//	cout << ans << '\n';
//	return 0;
//}