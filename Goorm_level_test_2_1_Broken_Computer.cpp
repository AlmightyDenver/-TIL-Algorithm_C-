#include <iostream>

using namespace std;
int N, C;
int key[100001];

int main() {
	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		cin >> key[i];
	}
	
	int cnt = 0;
	for (int i = N-1; i >= 0; i--) {
		if (key[i] - key[i - 1] <= C) cnt++;
		else break;
	}

	cout << cnt + 1 << '\n';
	return 0;

}
