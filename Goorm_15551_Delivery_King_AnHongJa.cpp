//#include <iostream>
//using namespace std;
//
//int N, start;
//int arr[11][11];
//bool visit[10] = { false, }; //for문으로 다음거 확인할거라 visit 1차원
//int maxi = 0;
//
//
//void solve(int k, int sum) {
//	if (k == start && sum != 0) {
//		if (sum > maxi) maxi = sum;
//		return;
//	}
//	else {
//		for (int i = 0; i < N; i++) {
//			if (visit[i]) continue;
//			if (arr[k][i] != 0) {
//				visit[i] = true;
//				solve(i, sum + arr[k][i]);
//				visit[i] = false;
//			}
//		}
//	}
//
//}
//
//int main() {
//	cin >> N;
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			cin >> arr[i][j];
//		}
//	}
//
//	for (int i = 0; i < N; i++) {
//		start = i;
//		solve(i, 0);
//	}
//	cout << maxi << '\n';
//	return 0;
//}