#include <string>
#include <iostream>
using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int ans[3];
    int tmp;
    int game = 0;
    for (int i = 0; i < dartResult.size(); i++) {
        int asc = int(dartResult[i]);

        if (asc == 49) {
            if (dartResult[i + 1] == '0') {
                tmp = 10;
                i++;
            }
            else tmp = 1;
        }
        else if (asc >= 48 && asc <= 57) tmp = asc - 48;

        else if (dartResult[i] == '#') ans[game-1] *= (-1);
        else if (dartResult[i] == '*') {
            ans[game - 1] *= 2;
            if (game >= 2) ans[game - 2] *= 2;
        }
        else if (dartResult[i] == 'S') {
            ans[game] = tmp;
            game++;
        }
        else if (dartResult[i] == 'D') {
            tmp *= tmp;
            ans[game] = tmp;
            game++;
        }
        else if (dartResult[i] == 'T') {
            tmp *= (tmp * tmp);
            ans[game] = tmp;
            game++;
        }
    }

    for (int i = 0; i < 3; i++) {
        answer += ans[i];
    }
    return answer;
}

int main() {
    string s = "1S*2T*3S";
    cout << solution(s) << '\n';

}