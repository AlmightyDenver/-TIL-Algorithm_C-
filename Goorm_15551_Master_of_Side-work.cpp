//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//int N;
//vector<pair<int, int>> vec;
//vector < pair<int, int>> answer_vec;
//
////끝나는시간(second) 기준 오름차순. 같으면 시작시간 (first) 오름차순(일찍시작먼저)
//bool cmpr(pair<int, int>& a, pair<int, int>& b) {
//	if (a.second == b.second) return a.first < b.first;
//	return a.second < b.second;
//}
//
//
//int main() {
//	cin >> N;
//	for (int i = 0; i < N; i++) {
//		int a, b;
//		cin >> a >> b;
//		vec.push_back(make_pair(a, b));
//	}
//	sort(vec.begin(), vec.end(), cmpr);
//
//	answer_vec.push_back(vec[0]);
//	int j = 0;
//	for (int i = j+1; i < N; i++) {
//		if (vec[i].first >= vec[j].second) {
//			answer_vec.push_back(vec[i]);
//			j = i;
//		}
//	}
//	cout << answer_vec.size() << '\n';
//	return 0;
//}