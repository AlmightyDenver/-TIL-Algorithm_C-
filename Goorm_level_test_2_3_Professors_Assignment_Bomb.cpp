#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<pair<int, int>>vec;

//시작 빠른->늦은 순, 마감 늦은 -> 빠른 순 정렬 
bool desc(pair<int, int> &a, pair<int, int> &b) {
	if (a.first == b.first) return a.second > b.second;
	else return a.first > b.first;
}

int check_Date(string str) {
	int m, d;
	if (str[0] == '1') {
		if (str[1] == '2' || str[1] == '1' || str[1] == '0') {
			m = stoi(str.substr(0, 2));
			str = str.substr(3, str.size() - 1);
		}
		else {
			m = 1;
			str = str.substr(2, str.size() - 1);
		}
	}
	else {
		m = stoi(str.substr(0, 1));
		str = str.substr(2, str.size() - 1);
	}
	d = stoi(str);
	return (m * 100 + d);
}


int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		string str1, str2;
		cin >> str1 >> str2;
		vec.push_back(make_pair(check_Date(str1),check_Date(str2)));
	}
	sort(vec.begin(), vec.end(), desc);
	for (int i = 0; i < vec.size(); ++i) {
		cout << vec[i].first << ' ' << vec[i].second << '\n';
	}
	for (int i = 0; i < vec.size()-1; ++i) {
		for (int j = i + 1; j < vec.size(); ++j) {
			if (vec[i].second > vec[j].second) {
				cout << "No" << '\n';
				return 0;
			}
		}
	}

	cout << "Yes" << '\n';
	return 0;
}