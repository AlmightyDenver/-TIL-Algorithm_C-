//�ִ� �ǳ� �� �ִ� ģ������ max���� �ݾ� �ٿ����� ã��

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
        int cnt = 0; //�� �ǳʴ� ¡�˴ٸ� ��
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
        //���ǳʴ� ¡�˴ٸ��� �ʹ� ������ right = mid-1���ؼ� �˻��� ģ���� �� ���̱�
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