//#include <vector>
//#include <iostream>
//#include <algorithm>
//
//int check(vector<int>& A, int tf) {
//	int cnt = 0;
//	for ((insigned int) i = 0; i < A.size(); ++i) {
//		//Ȧ���ڸ�
//		if (i % 2 == 1) {
//			if (A[i] == tf) continue;
//			else cnt++;
//		}
//		//¦���ڸ� 0�̾��
//		else {
//			if (A[i] != tf) continue;
//			else cnt++;
//		}
//	}
//	return cnt;
//}
//
//int solution(vector<int>& A) {
//	int ans = min(check(A, 1), check(A, 0));
//	return ans;
//}
//
//int main() {
//	vector<int> A = {1,0,1,0,1,1};
//	solution(A);
//	return 0;
//}