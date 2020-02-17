#include <iostream>
#include <algorithm>
using namespace std;
int n;
int triangle[500][500];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> triangle[i][j];
		}
	}
	
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) triangle[i][j] += triangle[i - 1][0];
			else if (j == i) triangle[i][j] += triangle[i - 1][j-1];
			else {
				triangle[i][j] += max(triangle[i - 1][j - 1], triangle[i - 1][j]);
			}
		}
	}


	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (ans < triangle[n - 1][i]) ans = triangle[n - 1][i];
	}
	cout << ans << '\n';
	return 0;
}