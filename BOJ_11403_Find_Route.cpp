//#include <iostream>
//
//using namespace std;
//int N;
//int map[101][101];
//
//int main() {
//	ios::sync_with_stdio(0); cin.tie(0);
//	cin >> N;
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			cin >> map[i][j];
//		}
//	}
//
//	for (int k = 0; k < N; k++) {
//		for (int i = 0; i < N; i++) {
//			for (int j = 0; j < N; j++) {
//				if (map[i][k] != 0 && map[k][j] != 0) {
//					map[i][j] = 1;
//
//				}
//			}
//		}
//	}
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			cout << map[i][j] << ' ';
//		}
//		cout << '\n';
//	}
//	return 0;
//}