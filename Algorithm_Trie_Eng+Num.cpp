//영문 숫자 혼합

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>;
using namespace std;

const int ALPHABET_SIZE = 26 + 10;

// trie node 
struct TrieNode
{
	struct TrieNode* children[ALPHABET_SIZE];

	// isEndOfWord is true if the node represents  end of a word 
	bool isEndOfWord;
};

// Returns new trie node (initialized to NULLs) 
struct TrieNode* getNode(void)
{
	struct TrieNode* pNode = new TrieNode;

	pNode->isEndOfWord = false;

	for (int i = 0; i < ALPHABET_SIZE; i++)
		pNode->children[i] = NULL;

	return pNode;
}


void insert(struct TrieNode* root, string key)
{
	struct TrieNode* pCrawl = root;

	for (int i = 0; i < key.length(); i++)
	{
		int index = key[i] - '0'; //lowerbound
		if (!pCrawl->children[index])
			pCrawl->children[index] = getNode();

		pCrawl = pCrawl->children[index];
	}

	// mark last node as leaf 
	pCrawl->isEndOfWord = true;
}

// Returns true if key presents in trie, else  false 
bool search(struct TrieNode* root, string key)
{
	struct TrieNode* pCrawl = root;

	for (int i = 0; i < key.length(); i++)
	{
		int index = key[i] - '0';
		if (!pCrawl->children[index])
			return false;

		pCrawl = pCrawl->children[index];
	}

	return (pCrawl->isEndOfWord && pCrawl != NULL);
}


string solution(vector<string> registered_list, string new_id) {
	string answer = "";



	struct TrieNode* root = getNode();

	// Construct trie 
	for (int i = 0; i < registered_list.size(); i++) {
		insert(root, registered_list[i]);
	}

	if (search(root, new_id)) {
		string str = "";
		int s_num = 0;
		for (int i = 0; i < new_id.size(); i++) {
			//숫자면
			if ((int)new_id[i] < 58) {
				string tmp = new_id.substr(i, new_id.size());
				if (tmp.size() != 0) {
					s_num = stoi(tmp);
					break;
				}
			}
			else {
				str += new_id[i];
			}
		}
		while (true) {
			new_id = str;
			s_num += 1;
			new_id += to_string(s_num);
			if (!search(root, new_id)) break;
		}
	}
	answer = new_id;
	cout << new_id;
	delete root;
	return answer;
}

int main() {
	//vector<string> registered_list = { "cow", "cow1", "cow2", "cow3", "cow4", "cow9", "cow8", "cow7", "cow6", "cow5" };
	//string new_id = "cow";//cow10
	//vector<string> registered_list = { "card", "ace13", "ace16", "banker", "ace17", "ace14" };
	//string new_id = "ace15";// ace15
	//vector<string> registered_list = {"bird99", "bird98", "bird101", "gotoxy"  };
	//string new_id = "bird98";//bird100
	vector<string> registered_list = { "bird999", "bird998", "bird1000","bird1002", "bird1001", "gotoxy" };
	string new_id = "bird998";//bird100

	solution(registered_list, new_id);
	return 0;
}

