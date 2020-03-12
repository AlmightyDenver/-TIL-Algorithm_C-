//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//int N;
//int memo[22];
//
//
//int main() {
//	ios::sync_with_stdio(0); cin.tie(0);
//	cin >> N;
//	for (int i = 0; i < N; i++) {
//		int t, p;
//		cin >> t >> p;
//		memo[i + 1] = max(memo[i + 1], memo[i]);
//		memo[i + t] = max(memo[i + t], memo[i] + p);
//	}
//
//	cout << memo[N] << '\n';
//	return 0;
//}