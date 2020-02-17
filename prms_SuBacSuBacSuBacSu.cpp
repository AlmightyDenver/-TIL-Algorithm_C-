#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(int n) {
    string answer = "";
    string su = "¼ö";
    string subac = "¼ö¹Ú";
    while (n > 0) {
        if (n == 1) {
            answer += su;
            return answer;
        }
        else {
            answer += subac;
            n -= 2;
        }
    }
    return answer;
}

int main() {
    int n = 3;
    cout <<solution(n) << '\n';
    return 0;
}