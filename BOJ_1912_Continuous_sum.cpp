#include <iostream>
#include <algorithm>
using namespace std;
int arr[100000];
int n;
int score[100000];
int maxi = -2e9;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	score[0] = arr[0];
	maxi = score[0];
	for (int i = 1; i < n; i++) {
		score[i] = max(arr[i], arr[i] + score[i - 1]);
		maxi = max(maxi, score[i]);
	}
	cout << maxi << ' ';
	return 0;
}