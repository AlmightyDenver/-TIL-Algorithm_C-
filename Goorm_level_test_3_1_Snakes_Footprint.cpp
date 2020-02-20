#include <iostream>
using namespace std;
int N, M;

void full() {
	for (int i = 0; i < M; i++) {
		cout << '#';
	}
	cout << '\n';
	return;
}

void dot() {
	for (int i = 0; i < M-1; i++) {
		cout << '.';
	}
	return;
}


int main() {
	cin >>N >> M;
	for (int i = 1; i <= N; i++) {
		if (i % 2 != 0) full();
		else if (i % 4 == 0) {
			cout << '#';
			dot();
			cout << '\n';
		}
		else {
			dot();
			cout << '#' << '\n';
		}
	}
	return 0;
}