#include <iostream>
using namespace std;
int main() {
	int N;
	cin >> N;
	while (N > 1) {
		for (int i = 2; i <= N; i++) {
			if (N % i == 0) {
				cout << i;
				N /= i;
				if (N != 1) cout << ' ';
				break;
			}
			
		}
	}
	if (N == 1) cout << '\n';
	return 0;
}