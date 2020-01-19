#include <iostream>
#include <algorithm>

using namespace std;

int k;
int lottery[6] = { 0, };
int* num = new int[k];

bool promising(int loc) {
	for (int i = 0; i < loc; i++) {
		if (lottery[i] >= lottery[loc]) return false;
	}
	return true;
}

void solve(int loc) {
	if (loc == 6) {
		int* curr = 0;
		curr = lottery;
		while (curr != lottery + 6) {
			cout << *(curr) << ' ';
			curr++;
		}
		cout << '\n';
	}
	else {
		for (int i = 0; i < k; i++) {
			lottery[loc] = num[i];
			if (promising(loc)) solve(loc + 1);
		}
	}
}

int main() {
	while (true) {
		cin >> k;
		if (k == 0) break;
		for (int i = 0; i < k; i++) {
			cin >> num[i];
		}
		solve(0);
		cout << '\n';
	}
	return 0;
}