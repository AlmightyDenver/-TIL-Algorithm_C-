#include <iostream>

using namespace std;
int N;
int map[2187][2187];
bool check[2187][2187];
int zero = 0, minus_one =0 , plus_one = 0;
int cnt = 0;

bool slice(int size) {
	//������ ���� ����
	for (int lim_y = 0; lim_y < N; lim_y += size) {
		for (int lim_x = 0; lim_x < N; lim_x += size) {
			if (check[lim_y][lim_x]) continue; //�� �κ��̸� continue
			int num = map[lim_y][lim_x]; //ù��ǥ ����
			bool flag = true;
			//ù ��ǥ ���ڿ� �ٸ��� break
			for (int i = lim_y; i < lim_y+size; i++) {
				for (int j = lim_x; j < lim_x+size; j++) {
					if (map[i][j] != num) {
						flag = false;
						break;
					}
				}
				if (!flag) break;
			}
			if (flag) {
				//���� �κ� check
				for (int i = lim_y; i < lim_y + size; i++) {
					for (int j = lim_x; j < lim_x + size; j++) {
						check[i][j] = true;
					}
				}
				//���� �� ����
				if (num == -1) minus_one++;
				else if (num == 0) zero++;
				else if (num == 1) plus_one++;
				cnt += size * size; //���� �κ� ����

			}
		}
	}
	if (cnt == N * N) return true;
	return false;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	//��� �κ� �������� /3 ������� ����
	for (int i = N; i >0; i/=3) {
		if(slice(i)) break;
	}


	cout << minus_one << '\n' << zero << '\n' << plus_one << '\n';
	return 0;
}