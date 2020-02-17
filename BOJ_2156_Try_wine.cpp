#include <iostream>
#include <algorithm>
using namespace std;
int n;
int wine[10000];
int memo[10000][3];

int main() {
	int ans = 0;

	//input
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> wine[i];
	}


	for (int i = 0; i < n; i++) {
		//�̹��� �ȸ��� => memo[i-1]���� ���� ū �� ��������
		memo[i][0] = max(max(memo[i - 1][0], memo[i - 1][1]), memo[i - 1][2]);
		//���� �ȸ԰� �̹��� ����
		memo[i][1] = memo[i-1][0] + wine[i];
		//���� �԰� �̹����� ����
		memo[i][2] = memo[i - 1][1] + wine[i];

	}

	ans = max(max(memo[n-1][0], memo[n-1][1]), memo[n-1][2]);
	cout << ans << '\n';
	return 0;
}