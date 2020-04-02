//#include <iostream>
//#include <algorithm>
//#include <memory.h>
//
//using namespace std;
//int N, K;
//int W[100], V[100];
//int memo[101][100001];
//
//int DP(int i, int w) {
//	if (i == N) return 0;
//	if (memo[i][w] != -1) return memo[i][w];
//	
//	//이번꺼 담기
//	int n1 = 0;
//	if (w + W[i] <= K)n1 = V[i] + DP(i + 1, w + W[i]);
//	//이번거 담지 않기
//	int n2 = DP(i + 1, w);
//	memo[i][w] = max(n1, n2);
//	return memo[i][w];
//}


//int main() {
//	ios::sync_with_stdio(0); cin.tie(0);
//	cin >> N >> K;
//	for (int i = 0; i < N; i++) {
//		cin >> W[i] >> V[i];
//	}
//	memset(memo, -1, sizeof(memo));
//
//	cout << DP(0, 0) << '\n';
//	return 0;
//}