//#include <iostream>
//
//using namespace std;
//int memo[31][31];
//
//int DP(int n, int m) {
//	if (memo[n][m] != 0) return memo[n][m];
//
//	if (n > 1 && m >= 1)memo[n][m] = DP(n - 1, m) + DP(n - 1, m - 1);
//	return memo[n][m];
//}
//
//int main() {
//	int T;
//	cin >> T;
//	int n, m;
//	//init
//	for (int i = 1; i < 31; i++) {
//		memo[i][1] = i;
//		memo[i][i] = 1;
//	}
//	for (int i = 0; i < T; i++) {
//		cin >> n >> m;
//		if (m > n) {
//			int tmp = n;
//			n = m;
//			m = tmp;
//		}
//		cout << DP(n, m) << '\n';
//	}
//}