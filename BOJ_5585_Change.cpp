#include <iostream>

using namespace std;
int m;
int coin[6] = { 500,100,50,10,5,1 };

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> m;
	int rest = 1000 - m;
	int ans = 0;

	
	for (int i = 0; i < 6; i++) {
		while(coin[i] <= rest && rest > 0) {
			rest -= coin[i];
			ans++;
		}
	}
	

	cout << ans << '\n';
	return 0;
}