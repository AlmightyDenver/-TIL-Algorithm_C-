#include <iostream>
#include<math.h>
using namespace std;
int N, M;


int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> M >> N;
	int und = sqrt(M);
	int ovr = sqrt(N);
	int sum = 0;
	int mini = -1;

	for (int i = und; i <= ovr; i++) {
		int num = i * i;
		if (num >= M && num <= N) {
			if (mini == -1) mini = num;
			sum += num;
		}
	}
	cout << mini << ' ' << sum << '\n';
	return 0;
}