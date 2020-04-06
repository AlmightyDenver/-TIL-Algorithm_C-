//Union Find
#include<iostream>
#include <memory.h>
#include <algorithm>
#include <map>

using namespace std;
const int MAX = 100001;
int root[MAX];
int node_cnt[MAX];
map<string, int> m;
int idx = 0;

int findd(int x) {
	if (root[x] == x) return x;
	else return root[x] = findd(root[x]);
}

int node_count(int x, int y) {
	//cout << x << ' ' << y << '\n';
	x = findd(x);
	y = findd(y);
	if (x != y) {
		root[y] = x;
		node_cnt[x] += node_cnt[y];
		node_cnt[y] = 1;
	}
	return node_cnt[x];
}
//
//int mapping(string name) {
//	pair<map<string, int>::iterator, bool> flag; //map에 삽입 성공 여부
//	flag = m.insert({ name, idx });
//	if (flag.second) {
//		idx++;
//		return idx-1;
//	}
//	else {
//		map<string, int>::iterator iter;
//		iter = m.find(name);
//		return iter->second;
//	}
//}

void init(int F) {
	m.clear();
	for (int i = 0; i < MAX; i++) {
		root[i] = i;
	}
	fill_n(node_cnt, MAX, 1);
	idx = 0;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T, F;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> F;
		init(F);
		string p1, p2;
		int a, b;
		for (int i = 0; i < F; i++) {
			cin >> p1 >> p2;

			if (m.count(p1) == 0) {
				m.insert({ p1, idx });
				idx++;
			}
			if (m.count(p2) == 0) {
				m.insert({ p2, idx });
				idx++;
			}
			cout << node_count(m[p1], m[p2]) << '\n';
			//a = mapping(p1);
			//b = mapping(p2);
			//cout << node_count(a, b) << '\n';
		}
		
	}
}