include <iostream>
#include <stdlib.h>

using namespace std;
int N;
int res = 0;
int col[15];

bool promising(int r) {
	for (int i = 0; i < r; i++) {
		if (col[r] == col[i] || abs(col[r] - col[i]) == (r - i)) return false;
	}
	return true;
}

void N_Queen(int r) {
	if (r == N) res++;
	else {
		for (int i = 0; i < N; i++) {
			col[r] = i;
			if (promising(r)) N_Queen(r + 1);

		}
	}
}

int main() {
	cin >> N;
	N_Queen(0);
	cout << res << '\n';
	return 0;
}
