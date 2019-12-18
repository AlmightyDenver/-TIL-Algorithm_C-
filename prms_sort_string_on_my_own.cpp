//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int N;
//bool compre(string a, string b) {
//	if (a.substr(N, 1) == b.substr(N, 1)) return a < b;
//	else return a.substr(N, 1) < b.substr(N, 1);
//}
//
//vector<string> solution(vector<string> strings, int n) {
//	N = n;
//	sort(strings.begin(), strings.end(), compre);
//	return strings;
//}
//
//int main() {
//	vector<string> str = { "abce", "abcd", "cdx" };
//	int n = 2;
//	solution(str, n);
//	return 0;
//}