#include <string>
#include <vector>

using namespace std;

string solution(string s) {

    int cnt = 1;
    for (int i = 0; i < s.size(); i++) {
        if (s.at(i) == ' ') cnt = 1;
        else {
            if (cnt % 2 != 0) s[i] = toupper(s[i]);
            else s[i] = tolower(s[i]);
            cnt++;
        }
    }
    return s;
}

int main() {
    string s = "try hello world";
    cout << solution(s);
    return 0;
}