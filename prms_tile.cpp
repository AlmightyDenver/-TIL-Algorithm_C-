//#include <string>
//#include <vector>
//
//using namespace std;
//
//long long solution(int N) {
//	long len[N];
//	if (N == 1) return 4;
//	else if (N == 2) return 6;
//	else {
//		len[0] = 1;
//		len[1] = 1;
//		for (int i = 2; i < N; i++) {
//			len[i] = len[i - 1] + len[i - 2];
//		}
//	}
//	long long answer = 0;
//	answer = (len[N - 1] * 4) + (len[N - 2] * 2);
//	return answer;
//}