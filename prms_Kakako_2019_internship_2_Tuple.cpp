#include <string>
#include <vector>
#include <cstring> //strtok
#include <algorithm>
#include <cstdlib> //stoi, atoi
using namespace std;

bool cmpr(string a, string b) {
    if (a.size() != b.size()) {
        return a.size() < b.size();
    }
    return  a < b;
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<string> tokens;
    s = s.substr(1, s.size() - 1);
    int st_idx = 0;
    int i = 1;
    while (s != "}") {
        if (s[i] == '{') {
            st_idx = i;
            i++;
        }
        else if (s[i] == '}') {
            string token = s.substr(st_idx + 1, i - 1);
            if (token[token.size() - 1] == '}') token =token.substr(0, token.size() - 1);

            //cout << token << '\n';
            tokens.push_back(token);
            s = s.substr(i + 1, s.size());
            i = 0;
            //cout << s;
        }
        else i++;
    }

    sort(tokens.begin(), tokens.end(), cmpr);
    vector<string> tmp;
    for (int i = 0; i < tokens.size(); i++) {
        string str = tokens[i];
        char* str_buff = new char[100000];
        strcpy(str_buff, str.c_str());
        char* token = strtok(str_buff, ",");
        while (token != nullptr) {
            if (std::find(tmp.begin(), tmp.end(), token) == tmp.end()) tmp.push_back(string(token));
            token = strtok(nullptr, ",");
        }
    }
        
    for (int i = 0; i < tmp.size(); i++) {
        answer.push_back(stoi(tmp[i]));
    }


    return answer;
}

int main() {
    //string s = "{{2},{2,1},{2,1,3},{2,1,3,4}}"; //[2, 1, 3, 4]
    string s = "{{4,2,3},{3},{2,3,4,1},{2,3}}";
    solution(s);
    return 0;
}