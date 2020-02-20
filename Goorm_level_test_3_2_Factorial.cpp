#include <iostream>
using namespace std;
int N;
long long memo[16];
int main() {
	cin >> N;
	memo[1] = 1;
	for (int i = 2; i <= N; i++) {
		memo[i] =i * memo[i - 1];
	}
	cout << memo[N];
	return 0;
}