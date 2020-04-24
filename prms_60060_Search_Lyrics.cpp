#include <string>
#include <vector>
#include <iostream>
#include <cstring>

using namespace std;


int char_to_idx(char key) {
    return key - 'a';
}

struct Trie {
    Trie* child[26];

    bool finish;
    int cnt;
    Trie() :finish(false), cnt(1) {
    for (int i = 0; i < 26; i++) {
        child[i] = 0;
        }
    }

    ~Trie() {
        for (int i = 0; i < 10; i++) {
            if (child[i]) delete child[i];
        }
    }

    void insert(const char* key) {
        if (*key == '\0') finish = true;
        else {
            int curr = *key - 'a';
            if (child[curr] == NULL) child[curr] = new Trie();
            else child[curr]->cnt++;
            child[curr]->insert(key + 1);
        }
    }

    int find(const char* key) {
        int curr = char_to_idx(*key);
        if (*key == '?') {
            int tmp = 0;
            for (int k = 0; k < 26; k++) {
                if (child[k] != NULL) {
                    tmp += child[k]->cnt;
                }
            }
            return tmp;
        }
        if (child[curr] == NULL) return 0;
        if (*(key + 1) == '?') return child[curr]->cnt;
        return child[curr]->find(key + 1);

    }

};

Trie* root[10001];
Trie* reroot[10001];

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer(queries.size(), 0);
    for (auto &key : words) {
        int sz = key.size();

        const char* chr = key.c_str();
        if (root[sz] == NULL) root[sz] = new Trie();
        root[sz]->insert(chr);

        string reversed_str = key;
        reverse(reversed_str.begin(), reversed_str.end());

        chr = reversed_str.c_str();
        if (reroot[sz] == NULL) reroot[sz] = new Trie();
        reroot[sz]->insert(chr);
    }

    int idx = 0;
    for (auto& key : queries) {
        int sz = key.size();

        if (key[sz - 1] == '?') {
            const char* chr = key.c_str();

            if (root[sz] == NULL) {
                idx++;
                continue;
            }
            else answer[idx] = root[sz]->find(chr);
        }
        else {
            string str = key;
            reverse(str.begin(), str.end());
            const char* chr = str.c_str();

            if (reroot[sz] == NULL) {
                idx++;
                continue;
            }
            else answer[idx] = reroot[sz]->find(chr);
        }
        idx++;
    }

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << ' ';
    }
    return answer;
}

int main() {
    vector<string> words = { "frodo", "front", "frost", "frozen", "frame", "kakao" };
    vector<string> queries = { "fro??", "????o", "fr???", "fro???", "pro?" };
    solution(words, queries);
    return 0;
}