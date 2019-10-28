//#include <string>
//#include <vector>
//#include <algorithm>
//#include <iostream>
//using namespace std;
//
//int ans;
//void dfs(int x, vector < vector<int>>computers[[]],  bool check[]) {
//
//	if (check[x]) return;
//	else {
//		check[x] = true;
//
//		for (int i = 0; i < computers[x].size(); i++) {
//			if (i != x && computers[x][i] == 1) {
//				dfs(i, computers, check);
//			}
//
//		}
//	}
//
//}
//
//
//int main(void) {
//	int n = 3;
//	bool check[3 + 1];
//	fill(check, check + 3+1,false);
//	vector<vector<int>> computers = { {1, 1, 0},{1, 1, 1},{0, 1, 1} };
//	int ans = 0;
//	for (int i = 0; i < n; i++) {
//		if (!check[i]) {
//			dfs(i, computers, check);
//			ans++;
//		}
//		
//	}
//	cout << ans;
//	return ans;
//}