//#include <iostream>
//#include <algorithm>
//using namespace std;
//int N;
//int time[16];
//int pay[16];
//int memo[22];
//
//void powerset(int curr, int sum) {
//	memo[curr] = max(sum, memo[curr]);
//	if (curr >= N) return;
//	powerset(curr + time[curr], sum + pay[curr]);
//	powerset(curr + 1, sum);
//}
//
//
//
//int main() {
//	ios::sync_with_stdio(0); cin.tie(0);
//	cin >> N;
//	for (int i = 0; i < N; i++) {
//		cin >> time[i] >> pay[i];
//	}
//
//	powerset(0, 0);
//	cout << memo[N];
//
//	return 0;
//}