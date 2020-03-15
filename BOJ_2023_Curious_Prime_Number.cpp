#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
int N;
vector<int> vec;
int firstPN[4] = { 2,3,5,7 };
int middlePN[4] = { 1,3,7,9 };

bool isPrime(int num) {
	for (int i = 3; i <= sqrt(num); i+=2) {
		if ((num % i) == 0) return false;
	}
	return true;
}


void makePN(int num) {
	if (num >= pow(10, N)) return;
	for (int i = 0; i < 4; i++) {
		num += middlePN[i];
 		if (isPrime(num)) {
			if (num > pow(10, N - 1)) vec.push_back(num);
			else {
				makePN(num * 10);
			}
			num -= middlePN[i];
		}
		else num -= middlePN[i];
	}
}



int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N;

	int pn[4] = { 2,3,5,7};
	if (N == 1) {
		for (int i = 0; i < 4; i++) {
			cout << pn[i] << '\n';
		}
		return 0;
	}

	for (int i = 0; i < 4; i++) {		
		int num = firstPN[i];
		num *= 10;
		makePN(num);
	}

	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << '\n';
	}
	return 0;
}
