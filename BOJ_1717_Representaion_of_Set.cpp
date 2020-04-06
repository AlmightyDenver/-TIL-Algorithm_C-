//union find
#include <iostream>

using namespace std;
int parent[1000000];


int Find(int x) {
	if (parent[x] == x) return x;
	else {
		int root = Find(parent[x]);
		parent[x] = root;
		return root;
	}
}

void Unionn(int x, int y) {
	int xroot = Find(x);
	int yroot = Find(y);
	if (xroot != yroot) parent[xroot] = yroot;
}

int main() {
	int n, m;
	int flag, a, b;
	
	//input
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i <= n; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < m; i++) {
		cin >> flag >> a >> b;
		if (flag == 0) Unionn(a, b);
		else {
			if (Find(a) == Find(b)) cout << "YES" << '\n';
			else cout << "NO" << '\n';
		}
	}

	return 0;
}