#include <iostream>
using namespace std;
int H, U, D, F;


int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> H >> U >> D >> F;

	int day = 1; //소요된 날짜
	double minus = (double)U * F / 100;
	bool flag = false;
	double top = 0;
	double bott = 0;
	while (true) {
		top = bott + U - minus * (day - 1);
		bott = top - D;
		if (top > H) {
			flag = true;
			break;
		}
		else if (bott < 0)break;
		day++;
	}
	if (flag) cout << "Success " << day;
	else cout << "Failure " << day;
	return 0;
}