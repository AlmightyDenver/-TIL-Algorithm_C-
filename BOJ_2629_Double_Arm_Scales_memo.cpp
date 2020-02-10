#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int N, M; //N ÃßÀÇ °¹¼ö. M ±¸½½ °¹¼ö
int sinkers[30];
int maxi = 0;
int marbles[7];
bool memo[31][30*500+1];

void powerset(int k, int sum) {
	if (k > N || sum > maxi) return;
	if (memo[k][sum] == true) return;
	memo[k][sum] = true;
	powerset(k + 1, sum + sinkers[k]);
	powerset(k + 1, sum);
	powerset(k + 1, abs(sum - sinkers[k]));
}
void solve() {
	powerset(0, 0);

	for (int i = 0; i < M; i++) {
		if (marbles[i] > maxi) cout << "N ";
		else if (memo[N][marbles[i]] == true) cout << "Y ";
		else cout << "N ";
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> sinkers[i];
		maxi += sinkers[i];
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> marbles[i];
	}

	solve();
	cout << '\n';

	return 0;
}