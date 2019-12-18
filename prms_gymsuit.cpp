//#include <string>
//#include <vector>
//#include <algorithm>
//#include<iostream>
//using namespace std;
//
//
//int solution(int n, vector<int> lost, vector<int> reserve) {
//	int answer = n-lost.size();
//	vector<bool> check_re(reserve.size(), false); //flase 안빌려줌
//	vector<bool> check_lo(lost.size(), false);
//	sort(lost.begin(), lost.end());
//	sort(reserve.begin(), reserve.end());
//
//	for (int i = 0; i < lost.size(); ++i) {
//		for (int j = 0; j < reserve.size(); ++j) {
//			if (!check_re[j] && lost[i] == reserve[j]) {
//				check_re[j] = true;
//				check_lo[i] = true;
//				answer++;
//				break;
//			}
//		}
//	}
//	for (int i = 0; i < lost.size(); ++i) {
//		for (int j = 0; j < reserve.size(); ++j) {
//			if (!check_lo[i] && !check_re[j]) {
//				//작은애가 먼저 확인
//				if (lost[i] == reserve[j] + 1) {
//					check_lo[i] = true;
//					check_re[j] = true;
//					answer++;
//					break;
//				}
//				else if (lost[i] == reserve[j] - 1) {
//					check_lo[i] = true;
//					check_re[j] = true;
//					answer++;
//					break;
//				}
//			}
//		}
//	}
//	cout << answer;
//	return answer;
//}
//
//int main() {
//	//int n = 5;
//	//vector<int> lost = { 2,4 };
//	//vector<int>reserve = { 1,3,5 };
//	int n = 5;
//	vector<int> lost = { 2,4 };
//	vector<int>reserve = { 5 };
//	solution(n, lost, reserve);
//	return 0;
//}