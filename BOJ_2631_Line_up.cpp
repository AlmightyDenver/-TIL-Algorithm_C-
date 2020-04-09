//DP - LIS
#include <iostream>

using namespace std;
int N, maxi = 0;
int arr[201];
int memo[201] = { 0, };

int DP() {
	//LIS
	for (int i = 0; i < N; i++) {
		memo[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j] && memo[i] < memo[j] + 1) memo[i] = memo[j] + 1;
		}
		if (maxi < memo[i]) maxi = memo[i];
	}
	//ans
	return N - maxi;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	cout << DP() << '\n';
	return 0;
}