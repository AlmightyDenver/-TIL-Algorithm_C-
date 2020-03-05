#include <iostream>

using namespace std;
int N, M, K;
int maxi = 0;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M >> K;
	maxi = N / 2 > M ? M : N/2;

	while (K > N - (maxi * 2) + M - maxi) {
		maxi -= 1;
		if (maxi == 0) break;
	}

	cout << maxi << '\n';
	return 0;
}