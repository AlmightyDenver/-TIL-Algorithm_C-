#include <string>
#include <vector>
#include <string.h> // memset
#include <iostream>
using namespace std;


vector<vector<bool>> toBin(vector<int> inputArr, int n, vector<vector<bool>>ary) {
	for (int i = 0; i < n; i++) {
		int j = 0;
		int k = inputArr[i];
		//2���� ��ȯ �Ųٷ� ���� ex) 8 == 1000(2) => 0001�� ����
		while (k > 0) {
			ary[i][j] = (ary[i][j] || (k % 2)); //arr2�϶� or
			j += 1;
			k /= 2;
		}
	}
	return ary;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	//2���� ������ 2���� �迭 ����, 0���� �ʱ�ȭ
	vector<vector<bool> > ary(n, vector<bool>(n, false));

	//2��������
	ary = toBin(arr1, n, ary);
	ary = toBin(arr2, n, ary);

	// answer.   0=> " ", 1 => "#"    
	vector<string> answer;
	for (int i = 0; i < n; i++) {
		string str = "";
		//�Ųٷ� ���������� �ٽ� �Ųٷ�
		for (int j = n - 1; j >= 0; j--) {
			if (ary[i][j]) str += "#";
			else str += " ";
		}
		answer.push_back(str);
	}
	return answer;
}
