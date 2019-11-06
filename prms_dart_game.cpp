#include <string>
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

vector<int> vec;

int findNumber(string result, int i) {
	int n;
	//0이면
	if (result[i - 1] == '0' && result[i - 2] != '1') n = 0;
	//10이면
	else if (i > 1 && result[i - 1] == '0' && result[i - 2] == '1') n = 10;
	else if ((int)result[i - 1] >= 0 && (int)result[i - 1] <= 9) n = (int)result[i - 1] - 48;
	else n = -1;
	return n;
}

int Squared(char s, int n) {
	int v = 0;
	if (s == 'T') v = (pow(n, 3));
	else if (s == 'D') v = (pow(n, 2));
	else if (s == 'S') v = n;
	return v;
}
int solution(string dartResult) {
	string result(dartResult);
	int n;
	int ans = 0;
	for (int i = 1; i < result.size(); i++) {
		int n = findNumber(result, i);
		if (n != -1) {
			int v = Squared(result[i], n);
			vec.push_back(v);

			ans += v;
			cout << "v " << v << '\n';

			if (result[i + 1] == '#') {
				ans -= (v * 2);
				cout << "# -" << v * 2 << '\n';
			}
			else if (result[i + 1] == '*') {
				ans += v;
				cout << "*1 " << v << '\n';
				if (vec.size() > 1) {
					ans += vec[vec.size() - 2];
					cout << "*2 " << vec[vec.size() - 2] << '\n';
				}
			}
		}

		// for(int i = 0; i< vec.size(); i++){
		//     cout << vec[i] << ' ';
		// }
	}
	cout << ans;
	return ans;
}

int main() {
	string dartResult = "1S2D*3T";
	solution(dartResult);
	return 0;
}