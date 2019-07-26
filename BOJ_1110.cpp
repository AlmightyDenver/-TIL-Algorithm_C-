//#include <stdio.h>
//using namespace std;
//
//int main()
//{
//	int n, N, cnt=1, ans = 0;
//	scanf("%d", &n);
//	N = n;
//	while (true) {
//		ans = n % 10 * 10 + ((n % 10 + n / 10) % 10);
//		if (ans != N) {
//			n = ans;
//			cnt += 1;
//			continue;
//		}
//		else break;
//	}
//	printf("%d", cnt);
//}