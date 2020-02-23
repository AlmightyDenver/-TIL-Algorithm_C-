#include <string>
#include <vector>
using namespace std;


string solution(int n) {
    string answer = "";
    while (n > 0) {
        if (n % 3 == 0) {
            answer.insert(0,"4");
            n /= 3;
            n -= 1;
        }
        else {
            answer.insert(0,to_string(n % 3));
            n /= 3;
        }
    }
    return answer;
}

int main() {
    int n = 12;
    cout << solution(n) << '\n';
    return 0;
}