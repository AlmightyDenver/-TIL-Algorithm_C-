//#include <string>
//#include <vector>
//
//using namespace std;
//
//vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
//	vector<vector<int>> answer;
//	for (int i = 0; i < arr1.size(); ++i) {
//		vector<int> r;
//		for (int j = 0; j < arr1[i].size(); ++j) {
//			int k = arr1[i][j] + arr2[i][j];
//			r.push_back(k);
//		}
//		answer.push_back(r);
//	}
//	return answer;
//}
//
//int main() {
//	vector<vector<int>> arr1 = { {1,2},{2,3} };
//	vector<vector<int>> arr2 = { {3,4},{5,6} };
//	solution(arr1, arr2);
//	return 0;
//}