#include <iostream>

using namespace std;
int N;
int ans[1001];

int main() {
	cin >> N;
	int num;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> num;
			ans[i] = ans[i] | num;
		}
	}

	for (int i = 0; i < N; i++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
	return 0;
}