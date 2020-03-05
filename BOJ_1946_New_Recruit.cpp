#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int T, N;
vector<pair<int, int> > vec_first;
vector<pair<int, int> > vec_sec;

bool cmpr(pair<int, int>& a, pair<int, int>& b) {
	return a.second < b.second;
}


int solve() {
	int cnt = 0;
	sort(vec_first.begin(), vec_first.end());
	sort(vec_sec.begin(), vec_sec.end(), cmpr);
	for (int i = 0; i < N; i++) {
		int second = vec_first[i].second;
		bool flag = true;
		for (int j = 0; j < second; j++) {
			if (vec_first[i].first > vec_sec[j].first) {
				flag = false;
				break;
			}
		}
		if (flag)cnt++;
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		vec_first.clear();
		vec_sec.clear();
		for (int j = 0; j < N; j++) {
			int p, q;
			cin >> p >> q;
			vec_first.push_back(make_pair(p, q));
			vec_sec.push_back(make_pair(p, q));
		}
		int ans = solve();
		cout << ans << '\n';
	}

	return 0;
}