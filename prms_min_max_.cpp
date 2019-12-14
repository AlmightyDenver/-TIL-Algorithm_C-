//#include <algorithm>
//#include <string>
//#include <vector>
//using namespace std;
//
//string solution(string s) {
//	int pos;
//	vector<int> vec;
//	//s에 공백 없을때까지 반복
//	while ((pos = s.find(" ")) != -1) {
//		//숫자 찾아서 (s의 0~공백앞까지) int 변환후vec에 추가
//		vec.push_back(stoi(s.substr(0, pos)));
//
//		//숫자, 공백 부분 자르기
//		if (s.size() > 1) s = s.substr(pos+1);
//		else s = "";
//	}
//	//마지막 숫자 추가
//	vec.push_back(stoi(s));
//	int mini = *min_element(vec.begin(), vec.end());
//	int maxi = *max_element(vec.begin(), vec.end());
//	return to_string(mini) + " " + to_string(maxi);
//}
//
//int main() {
//	string s = "-4 12 -3 -2 10";
//	cout << solution(s);
//	return 0;
//}