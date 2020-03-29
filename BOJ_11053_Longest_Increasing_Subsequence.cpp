#include <iostream>
#include <vector>

using namespace std;
int N;
vector<pair<int, int> > vec;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int k;
		cin >> k;
		vec.push_back({ k , 1 });
	}

	for (int i = 1; i < N; i++) {
		int maxi = -1;
		for (int j = 0; j < i; j++) {
			//�ڽź��� ���� �ֵ��� ���� ū �� ã��
			if (vec[j].first < vec[i].first && vec[j].second >= maxi) {
				maxi = vec[j].second;
			}
		}

		if (maxi != -1) vec[i].second += maxi;
	}

	int ans = 0;
	for (int i = 0; i < N; i++) {
		if (ans < vec[i].second) ans = vec[i].second;
	}
	cout << ans << '\n';
	return 0;
}