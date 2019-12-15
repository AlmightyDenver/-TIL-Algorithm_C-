//#include <string>
//#include <vector>
//#include <iostream>
//using namespace std;
//
//int solution(string s) {
//	int answer = 0;
//	int min = s.size();
//
//	for (int i = 1; i < s.size(); i++) {
//		//초기화
//		string last = "";
//		int tmp = s.size();
//		int cnt = 1;
//		for (int j = i; j < s.size(); j += i) {
//			//범위 넘지 않게
//			if (j + i <= s.size()) {
//				string s1 = s.substr(j - i, i);
//				string s2 = s.substr(j, i);
//				//처음 중복 발견시
//				if (s1 == s2 && s2 != last) {
//					tmp -= (i - 1);
//					cnt++;
//				}
//				//2번 이상 중복시
//				else if (s1 == s2 && s2 == last) {
//					tmp -= i;
//					cnt++;
//					if (cnt == 10 || cnt == 100 || tmp == 1000) tmp++;
//				}
//				//같지 않아지면
//				else if (s1 != s2 && j + i != s.size()) {
//					cnt = 1;
//				}
//				last = s1;
//			}
//		}
//		min = tmp < min ? tmp : min;
//	}
//	answer = min;
//	return answer;
//}
//
//int main() {
//	//string s = "aabbaccc"; //7
//	//string s = "ababcdcdababcdcd"; //9
//	//string s = "abcabcdede";//8
//	//string s = "aaaaaaaaaa";
//	string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";//5; 100ab;
//	//string s = "xababcdcdababcdcd"; //17
//	cout << solution(s);
//	return 0;
//}