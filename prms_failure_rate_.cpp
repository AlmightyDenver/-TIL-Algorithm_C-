//#include <string>
//#include <vector>
//
//#include <algorithm>
//using namespace std;
//
////실패율 내림차순, stage번호 오름차순
//bool compr(const pair<int, double>& a, const pair<int, double>& b) {
//	if (a.second != b.second) return a.second > b.second;
//	else return a.first < b.first;
//}
//
//vector<int> solution(int N, vector<int> stages) {
//	vector<int> answer;
//	vector < pair<int, double>> stg_frate;
//	double failure;
//	//분모 초기값
//	int tot = stages.size();
//	for (int i = 1; i < N + 1; ++i) {
//		double cnt = count(stages.begin(), stages.end(), i);
//		if (cnt == 0 || tot == 0) failure = 0;
//		else failure = cnt / tot;
//
//		tot -= cnt;
//		stg_frate.push_back(pair<int, double>(i, failure));
//	}
//	//실패율 높은순 -> 스테이지번호 낮은순
//
//	sort(stg_frate.begin(), stg_frate.end(), compr);
//	//stage번호만 담기
//	for (int i = 0; i < stg_frate.size(); ++i) {
//		answer.push_back(stg_frate[i].first);
//	}
//
//	return answer;
//}
//
//int main() {
//	//int N = 5;
//	//vector<int> stages = { 2,1,2,6,2,4,3,3 }; //[3,4,2,1,5]
//	//int N = 4;
//	//vector<int> stages = {4,4,4,4,4} //[4,1,2,3]
//	int N = 12;
//	vector<int> stages = {3,3,3,5,8,5};
//	vector<int> ans = solution(N, stages);
//	return 0;
//}