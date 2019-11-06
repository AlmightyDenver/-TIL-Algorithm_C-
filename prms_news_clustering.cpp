#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

//대문자로
string toUpper(string str) {
	transform(str.begin(), str.end(), str.begin(), ::toupper);
	return str;
}

//slicing
vector<string> Slicing(string str) {
	vector<string> vec;
	for (int i = 0; i < str.size() - 1; i++) {
		string st = "";
		if (65 <= (int)str[i] && (int)str[i] <= 90 && 65 <= (int)str[i + 1] && (int)str[i + 1] <= 90) {
			st += str[i];
			st += str[i + 1];
			vec.push_back(st);
		}
	}
	return vec;
}


//교집합
vector<string> Inte(vector<string>& v1, vector<string>& v2) {
	vector<string> vec;
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(vec));
	return vec;
}

int solution(string str1, string str2) {
	// 대문자로
	str1 = toUpper(str1);
	str2 = toUpper(str2);

	//slicing
	vector<string> v1 = Slicing(str1);
	vector<string> v2 = Slicing(str2);

	//교집합 합집합
	vector<string> vec_inte = Inte(v1, v2);
	int inte = vec_inte.size();
	int uni = v1.size() + v2.size() - vec_inte.size();

	//자카드 유사도 구하기
	double jaka;
	if (inte == 0 && uni == 0) jaka = 1;
	else if (inte == 0 || uni == 0) return 0;
	else jaka = (double)inte / (double)uni;

	jaka *= 65536;
	//정수부분만
	return (int)jaka;
}