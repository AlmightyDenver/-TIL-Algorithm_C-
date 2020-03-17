#include <iostream>

using namespace std;

int main() {
	int N, val;
	string cmd;
	int sett = 0;

	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> cmd;
		if (cmd == "add") {
			cin >> val;
			sett = sett | (1 << val);
		}
		else if (cmd == "remove") {
			cin >> val;
			sett &= ~(1 << val);
		}
		else if (cmd == "check") {
			cin >> val;
			if (sett & (1 << val)) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if (cmd == "toggle") {
			cin >> val;
			sett ^= (1 << val);
		}
		else if (cmd == "empty") sett = 0;
		else sett = (1 << 21) - 1;
	}
	return 0;
}