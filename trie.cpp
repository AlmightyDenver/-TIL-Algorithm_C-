#include <iostream>

using namespace std;

//대문자면 'A', 소문자면 'a', 숫자면 '0'
int char_to_index(char c) {
	return c - 'A';
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

	bool find(const char* key) {
		if (*key == '\0') return true;
		if (finish) return false;
		int curr = char_to_index(*key);
		return child[curr]->find(key + 1);
	}
};


int main() {
	Trie* root = new Trie();
	int N;
	cin >> N;
	char words[100][100];
	for (int i = 0; i < N; i++) {
		cin >> words[i];
	}

	for (int i = 0; i < N; i++) {
		root->insert(words[i]);
	}
	
	char find_lists[100][100] = {};
	bool flag = false;
	for (int i = 0; i < N; i++) {
		if (root->find(find_lists[i]) == false) {
			flag = false;
			break;
		}
	}
	
	if (flag) cout << "Exist";
	else cout << "Not Exist";
		
	return 0;
}