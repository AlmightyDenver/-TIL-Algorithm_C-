//#include <string>
//#include <vector>
//
//using namespace std;
//
//string solution(int a, int b) {
//	string answer = "";
//	vector<string> day = { "THU","FRI","SAT","SUN","MON","TUE","WED" };
//	vector<int> days = { 0,31,29,31,30,31,30, 31,31,30, 31,30, 31 };
//	int sum = 0;
//	for (int i = 0; i < a; ++i) {
//		sum += days[i];
//	}
//	sum += b;
//	answer = day[sum % 7];
//	return answer;
//}
//
//int main() {
//	int a = 5;
//	int b = 24;//tue
//	solution(a, b);
//	return 0;
//}
//
//
