//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//int N;
//vector<pair<int, int>> vec;
//
//
//int main() {
//	cin >> N;
//	for (int i = 0; i < N; i++) {
//		int a, b;
//		cin >> a >> b;
//		//끝나는시간 - 시작시간 순 저장(=> sort따로 정의 불필요)
//		vec.push_back(make_pair(b, a));
//	}
//	sort(vec.begin(), vec.end());
//	 
//	int ans = 1; //맨  처음일(가장 끝나는 일)
//	int last = vec[0].first;
//	for (int i = 1; i < N; i++) {
//		if (vec[i].second >= last) {
//			ans++;
//			last = vec[i].first;
//		}
//	}
//	cout << ans << '\n';
//	return 0;
//}