//#include <algorithm>
//#include <iostream>
//using namespace std;
//
//int height[9];
//int n = 9;
//
//int main() {
//	int sum = 0;
//	for (int i = 0; i < n; i++) {
//		cin >> height[i];
//		sum += height[i];
//	}
//
//	sort(height, height + n);
//
//	for (int i = 1; i < n; i++) {
//		for (int j = i + 1; j < n; j++) {
//			if (sum - height[i] - height[j] == 100) {
//				for (int k = 0; k < n; k++) {
//					if (k == i || k == j) continue;
//					else cout << height[k] << '\n';
//				}
//				return 0;
//			}
//		}
//	}
//	return 0;
//}