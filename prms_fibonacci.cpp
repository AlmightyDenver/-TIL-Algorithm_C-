//#include <string>
//#include <vector>
//
//using namespace std;
//
//int solution(int n) {
//	vector<int> fibo(n + 1, 0);
//	fibo[0] = 0;
//	fibo[1] = 1;
//	for (int i = 2; i <= n; i++) {
//		fibo[i] = (fibo[i - 1] + fibo[i - 2]) % 1234567;
//	}
//	return fibo[n];
//}
//
//int main() {
//	int n = 10;
//	solution(n);
//	return 0;
//}