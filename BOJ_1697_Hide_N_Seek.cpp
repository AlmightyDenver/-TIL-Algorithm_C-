#include <iostream>
#include <queue>
using namespace std;
int N, K;
bool visit[100001] = { false, };

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> K;
	if (K == 0) {
		cout << N << '\n';
		return 0;
	}
	queue<pair<int, int> > q;
	visit[N] = true;
	q.push(make_pair(N, 0));
	int cnt = 0;
	int curr = 0;
	while (!q.empty()) {
		curr= q.front().first;
		cnt = q.front().second;
		q.pop();
		cout << cnt << ' ' << curr << '\n';
		cnt++;
		if (curr == K) {
			break;
		}
		else {
			if (curr - 1 > 0 && visit[curr- 1] == false) {
				visit[curr - 1] = true;
				q.push(make_pair(curr - 1, cnt));
			}
			if (curr + 1 <= 100000){
				if (visit[curr + 1] == false) {
					visit[curr + 1] = true;
					q.push(make_pair(curr + 1, cnt));
				}
			}

			if (curr * 2 <= 100000){
				if (visit[curr * 2] == false) {
					visit[curr * 2] = true;
					q.push(make_pair(curr * 2, cnt));
				}
			}
		}
		
	}
	cout << cnt - 1 << '\n';
	return 0;
}