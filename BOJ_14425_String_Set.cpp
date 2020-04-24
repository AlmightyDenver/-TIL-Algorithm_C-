//문자열 전체가 똑같은 갯수

#include <iostream>
#include <memory.h>
using namespace std;
char str[501];

int char_to_index(char c) {
	return c - 'a';
}


struct Trie {
	Trie* child[26];

	//Constructor 생성자
	bool finish;
	Trie() :finish(false) {
		for (int i = 0; i < 26; i++) child[i] = 0;
	}

	//소멸자
	~Trie() {
		for (int i = 0; i < 26; i++) {
			if (child[i]) delete child[i];
		}
	}

	void insert(const char* key) {
		if (*key == '\0') finish = true;
		else {
			int curr = char_to_index(*key);
			if (child[curr] == 0) child[curr] = new Trie();
			child[curr]->insert(key + 1);
		}
	}

	Trie* find(char* key)
	{
		if (*key == NULL)
		{
			return this; //끝까지 오면 자신 반환
		}
		int index = *key - 'a';
		if (child[index] == NULL) return NULL;//길이 없으면 NULL반환
		return child[index]->find(key + 1);//다음것 탐색
	}
};


int main() {
	int N, M;
	cin >> N >> M;
	
	Trie* root = new Trie();
	for (int i = 0; i < N; i++) {
		memset(str, NULL, sizeof(str));
		cin >> str;
		root->insert(str);
	}

	int ans = 0;
	for (int i = 0; i < M; i++) {
		memset(str, NULL, sizeof(str));
		cin >> str;
		Trie* res = root->find(str);
		if (res != NULL && res->finish)
			++ans;
	}
	
	cout << ans << '\n';
	delete root;
	return 0;
}