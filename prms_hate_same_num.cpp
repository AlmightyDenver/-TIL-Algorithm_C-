//#include <vector>
//#include <iostream>
//
//using namespace std;
//
//vector<int> solution(vector<int> arr) {
//	vector<int> ans = {};
//	if (arr.size() == 0) return ans;
//	else if (arr.size() >= 1) ans.push_back(arr[0]);
//	if(arr.size() > 1) {
//		int pre = arr[0];
//		for (int i = 1; i < arr.size(); ++i) {
//			if (arr[i] != pre) {
//				ans.push_back(arr[i]);
//				pre = arr[i];
//			}
//		}
//	}
//	return ans;
//		
//}
//
//int main() {
//	vector<int> arr = { 1,1,3,3,0,1,1 ,0};
//	solution(arr);
//	return 0;
//}