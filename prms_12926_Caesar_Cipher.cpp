#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string s, int n) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != ' ') {
            //소문자인데 더해서 z(122)넘으면
            if (int(s[i]) >= 97 && int(s[i]) + n > 122) s[i] = char(int(s[i]) + n - 26);
            //대문자인데 Z(90)넘으면
            else if (int(s[i]) <= 90 && int(s[i]) + n > 90) s[i] = char(int(s[i] + n - 26));
            else s[i] = char(int(s[i]) + n);
        }
    }
    return s;
}

int main() {
    string s = "a B z";
    int n = 4;
    cout << solution(s, n) << '\n';
    return 0;
}