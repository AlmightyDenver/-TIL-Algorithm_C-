#include <vector>
#include <iostream>
#include <algorithm>

int check(vector<int>& A, int tf) {
	int cnt = 0;
	for ((insigned int) i = 0; i < A.size(); ++i) {
		//홀수자리
		if (i % 2 == 1) {
			if (A[i] == tf) continue;
			else cnt++;
		}
		//짝수자리 0이어야
		else {
			if (A[i] != tf) continue;
			else cnt++;
		}
	}
	return cnt;
}

int solution(vector<int>& A) {
	int ans = min(check(A, 1), check(A, 0));
	return ans;
}

int main() {
	vector<int> A = {1,0,1,0,1,1};
solution(A);
	return 0;
}
