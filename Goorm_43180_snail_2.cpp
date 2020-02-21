#include <iostream>
using namespace std;
int H, U, D, F;


int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> H >> U >> D >> F;
	if (U == 0 && D == 0 && F == 0) {
		cout << "Failure " << 0;
		return 0;
	}
	double h = (double)0; //현재 높이
	int day = 1; //소요된 날짜
	double capa = (double)U;
	double minus = (double)U * F / 100;
	bool flag = false;
	while (true) {
		h += capa;
		if (h > H) {
			flag = true;
			break;
		}
		//cout << h << ' ';
		h -= D;
		if (h < 0)break;
		//cout << h << ' ' << day <<'\n';
		capa -= minus;
		day++;
	}
	cout << h << '\n';
	if (flag) cout << "Success " << day;
	else cout << "Failure " << day;
	return 0;
}