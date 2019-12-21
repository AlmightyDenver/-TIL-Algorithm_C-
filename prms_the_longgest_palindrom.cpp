//#include <iostream>
//#include <string>
//#include <iostream>
//using namespace std;
//int solution(string s)
//{
//	int answer = 0;

//	int tmp = 0;
//	int max = 0;
//	for (int i = 1; i < s.size(); i++) {
//		string str1, str2;
//		//abba || aba
//		if (s[i-1] == s[i] || s[i - 1] == s[i + 1]) {
//			str1 = s.substr(0, i);
//			str2 = s.substr(i, i + i);
//			//cout << str1 << ' ' << str2 << '\n';
//		}
//		if ((str1.size() + 1) == str2.size()) tmp = str1.size() * 2 + 1;
//		else if (str1.size() == str2.size()) tmp = str1.size() * 2;
//		
//		if (max < tmp) max = tmp;
//	}
//	answer = max;
//	cout << answer;
//	return answer;
//}
//
//int main() {
//	//string s = "abcdcba";//7
//	//string s = "abacde"; //3
//	//string s = "ABCCBA"; //6
//	//string s = "abacdedcaba";//11
//	string s = "abcdadadrtkghk";//5
//	solution(s);
//	return 0;
//}