#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool arr[1000001];

int Prime(int n) {
    int i = 2;
    while (i <= n) {
        //� �� k�� ������ arr[i] = true�� ��
        if (!arr[i]) {
            //�ڽ��� �����ϰ�⶧���� *2����
            int j = 2;
            while (i*j <= n) {
                arr[i * j] = true;
                j++;
            }
        }
        i++;
    }

    //false�� �� ã��
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