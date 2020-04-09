//DP
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int memo[101];

int DP(int x) {
	if (x < 1 || memo[x] != 0) return memo[x];
	double sqrtt = 0;
	sqrtt = sqrt((double)x);
	//제곱수인경우
	if (sqrtt - (int)sqrtt == 0) return memo[x] = DP(x - 1)+1;
	else return memo[x] = DP(x-1);
}

int main() {
	int T;
	cin >> T;
	fill_n(memo, 0, 101);
	int N;
	for (int i = 0; i < T; i++) {
		cin >> N;
		//DP(N + 1);
		cout << DP(N) << '\n';
	}

	return 0;
}