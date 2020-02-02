#include <iostream>
#include <algorithm>
using namespace std;
int L, C;
char alphabet[26];
bool visit[26];
char arr[26];

int aeiou() {
	int cnt = 0;
	for (int i = 0; i < L; i++) {
		if (alphabet[arr[i]] == 'a' || alphabet[arr[i]] == 'e' || alphabet[arr[i]] == 'i' || alphabet[arr[i]] == 'o' || alphabet[arr[i]] == 'u') cnt++;
	}
	return cnt;
}

void dfs(int depth) {
	if (depth == L) {
		int vowel = aeiou();
		if (vowel >= 1 && L-vowel >= 2) {
			for (int i = 0; i < L; i++) {
				cout << alphabet[arr[i]];
			}
			cout << '\n';
		}
		
		return;
	}



	for (int i = 0; i < C; i++) {
		if (!visit[i] && i > arr[depth - 1]) {
			visit[i] = true;
			arr[depth] = i;
			dfs(depth + 1);

			visit[i] = false;
		}
	}

}

int main() {
	//input
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> L >> C;
	for (int i = 0; i < C; i++) {
		cin >> alphabet[i];
	}
	sort(alphabet, alphabet + C);

	for (int i = 0; i < C; i++) {
		visit[i] = true;
		arr[0] = i;
		dfs(1);
		visit[i] = false;
	}

	return 0;
}