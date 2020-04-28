//최대 건널 수 있는 친구들을 max부터 반씩 줄여가며 찾기

#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> stones, int k) {
    int left = 0;
    int right = 2000000000;
    int mid;
    while (left <= right) {
        mid = (left + right) / 2;
        int cnt = 0; //못 건너는 징검다리 수
        bool flag = true;
        for (int i = 0; i < stones.size(); i++) {
            if (stones[i] - mid <= 0) {
                cnt++;
            }
            else cnt = 0;

            if (cnt >= k) {
                flag = false;
                break;
            }
        }
        //못건너는 징검다리가 너무 많으면 right = mid-1로해서 검사할 친구들 수 줄이기
        if (!flag) right = mid - 1;
        else left = mid + 1;

    }
    //
    return left;
}

int main() {
    vector<int> stones = { 2, 4, 5, 3, 2, 1, 4, 2, 5, 1 };
    int k = 3;
    solution(stones, k);
    return 0;
}