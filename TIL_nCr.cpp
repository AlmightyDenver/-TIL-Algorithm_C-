//#include <iostream>
//
//using namespace std;
//
//long combi(int, int);
//
//int main() {
//	int n, r;
//	for (n = 0; n <= 5; n++) {
//		for (r = 0; r <= n; r++) {
//			cout << n << "C" << r << " = " << combi(n, r) << " ";
//		}
//		cout << "\n";
//	}
//	return 0;
//}
//
//long combi(int n, int r) {
//	long c = 1;
//	for (int i = 1; i <= r; i++) {
//		c = c*(n-i+1)/i;
//	}
//	return c;
//}