#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool arr[1000001];

int Prime(int n) {
    int i = 2;
    while (i <= n) {
        //어떤 수 k의 배수라면 arr[i] = true일 것
        if (!arr[i]) {
            //자신을 제외하고기때문에 *2부터
            int j = 2;
            while (i*j <= n) {
                arr[i * j] = true;
                j++;
            }
        }
        i++;
    }

    //false인 애 찾기
    int cnt = 0;
    for (int i = 2; i <= n; i++) {
        if (!arr[i])cnt++;
    }
    return cnt;
}

int solution(int n) {
    int answer = 0;
    arr[0] = true;
    arr[1] = true;
    answer = Prime(n);
    return answer;
}

int main() {
    int n = 20;
    solution(n);
    return 0;
}