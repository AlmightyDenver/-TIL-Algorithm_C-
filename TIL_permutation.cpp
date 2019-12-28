////next_permutation
////prev_permutation
////다음 순열이 없다면 false반환
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int main() {
//	vector<int> v = { 1,2,3,4 };
//
//	cout << " ***** Next_permutation ***** " << '\n';
//	do {
//		for (int i = 0; i < v.size(); ++i) {
//			cout << v[i] << ' ';
//		}
//		cout << '\n';
//	} while (next_permutation(v.begin(), v.end()));
//
////1234
////12243
////1324
////...
////4312
////4321
//
//
//	v = { 4,3,2,1 };
//	cout << '\n\n\n' << " ***** prev_permutation ***** " << '\n';
//	do {
//		for (int i = 0; i < v.size(); ++i) {
//			cout << v[i] << ' ';
//		}
//		cout << '\n';
//	} while (prev_permutation(v.begin(), v.end()));
//	//4 3 2 1
//	//4 3 1 2
//	//4 2 3 1
//	//	...
//	//1 3 2 4
//	//1 2 4 3
//	//1 2 3 4
//	return 0;
//}
//
//
//
