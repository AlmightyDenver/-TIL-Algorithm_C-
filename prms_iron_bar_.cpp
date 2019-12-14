//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int solution(string s) {
//	int ans = 0;
//	int cnt = 0;
//	int bar = 0;
//	// idx = 1 부터 시작
//	for (int i = 1; i < s.size(); i++) {
//		string bracket = s.substr(i, 1);
//		string front_b = s.substr(i - 1, 1);
//		//(->cnt++, )->cnt--
//		if (bracket == "(") cnt++;
//		else cnt--;
//
//		//(( -> bar++
//		if (front_b == "(" && bracket == "(") bar++;
//
//		//() -> ans
//		if (front_b == "(" && bracket == ")") {
//			ans += cnt + bar + 1;
//			bar = 0;
//		}
//	}
//	return ans;
//}
//int main() {
//	string s = "";
//	cout << solution(s);
//	return 0;
//}