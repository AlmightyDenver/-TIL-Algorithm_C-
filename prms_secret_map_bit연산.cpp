#include <string>
#include <vector>
#include <math.h>
#include <iostream>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer;
	for (int i = 0; i < arr1.size(); i++) {
		int k = arr1[i];
		int q = arr2[i];
		string str = "";
		for (int j = n - 1; j >= 0; j--) {
			if ((1 & (k >> j)) || (1 & (q >> j))) str += "#";
			else str += " ";
		}
		answer.push_back(str);
	}
	return answer;
}