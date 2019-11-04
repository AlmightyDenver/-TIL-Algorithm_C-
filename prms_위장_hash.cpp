#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
	int n = clothes.size();
	//map���� string key, int value
	map<string, int> m;
	map<string, int>::iterator iter;

	//����key�� �������� ������ �߰�, �ƴϸ� value++
	for (int i = 0; i<n; i++) {
		if(m.find(clothes[i][1]) == m.end()) m[clothes[i][1]] = 1;
		else m[clothes[i][1]]++;
	}


	int ans = 1;
	for (iter = m.begin(); iter != m.end(); iter++) {
		 ans *= (iter->second +1);
	}
	cout << ans - 1;
	return ans - 1;
}

int main() {
	vector<vector<string>> clothes = { {"yellow_hat", "headgear"},{"blue_sunglasses", "eyewear"},{"green_turban", "headgear"} };
	solution(clothes);
	return 0;
}