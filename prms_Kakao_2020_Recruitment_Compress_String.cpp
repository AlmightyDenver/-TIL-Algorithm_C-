#include <string>
#include <vector>
using namespace std;

int solution(string s) {
    if (s.size() < 2) return 1;
    int answer = 10000;
    //i : slicing 할 길이
    for (int i = 1; i <= s.size()/2; i++) {
        //dup : 중복된 문자 수
        int dup[2001] = { 1, };
        for (int j = 0; j < 2001; j++) {
            dup[j] = 1;
        }
        int len = s.size();

        for (int j = 0; j < s.size()-i; j+=i) {
            if (s.substr(j, i) == s.substr(j + i,  i)) {
                len -= i;
                dup[j + i] = dup[j] + 1;
                if (dup[j] == 1 || dup[j+i] == 10 || dup[j + i] == 100|| dup[j + i] == 1000) len += 1;
            }
        }
        if (answer > len)answer = len;
    }
    return answer;
}

int main() {
    //string s = "aabbaccc";
    //string s = "goooooodbye";
    string s = "aa";
    solution(s);
    return 0;
}