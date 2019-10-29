#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int solution(vector<vector<int>> triangle) {
	int answer = 0;
	int n = triangle.size();

	int** memo = new int* [n];
	for (int i = 0; i < n; ++i) {
		memo[i] = new int[i + 1]; //동적할당
		memset(memo[i], -1, sizeof(int) * i + 1); //초기값
	}
	memo[0][0] = triangle[0][0];

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
			if (memo[i][j] != -1) {
				if (j == 0) memo[i][j] = triangle[i][j] + memo[i - 1][j];
				else memo[i][j] = triangle[i][j] + memo[i - 1][j - 1];
			}
			else {
				int rigt = triangle[i][j] + memo[i - 1][j];
				int lft = triangle[i][j] + memo[i - 1][j - 1];
				memo[i][j] = lft > rigt ? lft : rigt;
			}
		}
	}
	int mx = memo[n - 1][0];
	for (int i = 0; i < n; i++) {
		if (mx < memo[n - 1][i]) mx = memo[n - 1][i];
	}
	return mx;
}


