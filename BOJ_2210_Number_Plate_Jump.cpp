#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int map[5][5];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
vector<int> vec;


void permu(int cnt, int x, int y, int num) {
	//�ߺ����� �ϼ��̸�
	if (cnt == 6) {
		vec.push_back(num);
		return;
	}

	//�ƴϸ� 0,1,2,3 �߿� �߰�
	for (int i = 0; i < 4; i++) {
		//���� �ȳ�����
		int nx = x + dx[i];
		int ny = y + dy[i];
		int n = num;
		if (nx >= 0 && ny >= 0 && nx < 5 && ny < 5) {
			n *= 10;
			n += map[nx][ny];
			permu(cnt + 1, nx, ny, n);
		}
	}
}

void solve() {
	//���� �ʱ� �ڸ�
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			permu(1, i, j, map[i][j]);
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> map[i][j];
		}
	}
	solve();

	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	cout << vec.size() << '\n';
	//for (int i = 0; i < vec.size(); ++i) {
	//	cout << vec[i] << '\n';
	//}
	return 0;
}