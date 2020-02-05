#include <iostream>
#include <queue>
using namespace std;

int T, N, M;

void clearQueue(priority_queue<int>& q) {
	priority_queue<int> empty;
	swap(q, empty);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N >> M;

		priority_queue<int> pq;
		vector<int> q;
		int ans = 0;
		//input
		for (int i = 0; i < N; i++) {
			int n;
			cin >> n;
			pq.push(n);
			q.push_back(n);
		}

		int last = 0;
		int first = 0;
		while (!pq.empty()) {
			for (int j = first; j < q.size(); ++j) {
				if (pq.top() == q[j]) {
					if (j == M) {
						cout << ans + 1 << '\n';
						clearQueue(pq);
						break;
					}
					q[j] = 0;
					first = j + 1;
					ans++;
					}
				}
			if (first != 0) {
				for (int j = 0; j < first; ++j) {
					if (pq.top() == q[j]) {
						if (j == M) {
							cout << ans + 1 << '\n';
							clearQueue(pq);
							break;
						}
						q[j] = 0;
						first = j + 1;
						ans++;

					}
				}
			}
			if(!pq.empty()) pq.pop();
		}
	}
	return 0;
}