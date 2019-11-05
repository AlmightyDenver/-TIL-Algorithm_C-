#include <string>
#include <vector>
#include <string.h> // memset
#include <iostream>
using namespace std;


vector<vector<bool>> toBin(vector<int> inputArr, int n, vector<vector<bool>>ary) {
	for (int i = 0; i < n; i++) {
		int j = 0;
		int k = inputArr[i];
		//2진법 변환 거꾸로 저장 ex) 8 == 1000(2) => 0001로 저장
		while (k > 0) {
			ary[i][j] = (ary[i][j] || (k % 2)); //arr2일때 or
			j += 1;
			k /= 2;
		}
	}
	return ary;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	//2진법 저장할 2차원 배열 선언, 0으로 초기화
	vector<vector<bool> > ary(n, vector<bool>(n, false));

	//2진법으로
	ary = toBin(arr1, n, ary);
	ary = toBin(arr2, n, ary);

	// answer.   0=> " ", 1 => "#"    
	vector<string> answer;
	for (int i = 0; i < n; i++) {
		string str = "";
		//거꾸로 저장했으니 다시 거꾸로
		for (int j = n - 1; j >= 0; j--) {
			if (ary[i][j]) str += "#";
			else str += " ";
		}
		answer.push_back(str);
	}
	return answer;
}
