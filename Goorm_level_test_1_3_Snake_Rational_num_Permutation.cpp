#include <iostream>
using namespace std;
int N;
int dx[4] = {0, 1, 1,-1};
int dy[4] = {1, -1,0, 1};

int main() {
	cin >> N;
	int x = 0;
	int y = 0;
	N -= 1;
	while (N > 0) {
		if (x == 0 && (y == 0 || y % 2 == 0)) {
			x += dx[0];
			y += dy[0];
			N--;
		}
		else if (x == 0 && y % 2 != 0) {
			while (y > 0) {
				x += dx[1];
				y += dy[1];
				N--;
				if (N == 0)break;
			}
		}
		else if (x % 2 != 0 && y == 0) {
			x += dx[2];
			y += dy[2];
			N--;
		}
		else if (x % 2 == 0 && y == 0) {
			while (x > 0) {
				x += dx[3];
				y += dy[3];
				N--;
				if (N == 0) break;
			}
		}
	}
	cout << x + 1 << '/' << y + 1 << '\n';
	return 0;
}