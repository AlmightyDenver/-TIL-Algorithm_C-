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
//		//�����½ð� - ���۽ð� �� ����(=> sort���� ���� ���ʿ�)
//		vec.push_back(make_pair(b, a));
//	}
//	sort(vec.begin(), vec.end());
//	 
//	int ans = 1; //��  ó����(���� ������ ��)
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