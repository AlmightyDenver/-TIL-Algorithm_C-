#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0;
    vector<int> count;
    for (int i = 0; i < stones.size(); i++) {
        int tmp = 0;
        int dir = 0;
        while (true) {
            if (i + dir < stones.size() && stones[i + dir] <= stones[i]) dir++;
            else {
                tmp += dir;
                break;
            }
        }
        dir = 1;
        while (true) {
            if (i - dir >= 0 && stones[i - dir] <= stones[i]) dir++;
            else {
                tmp += (dir-1);
                break;
            }
        }
        
        count.push_back(tmp);
    }
    for (int i = 0; i < count.size(); i++) {
        cout << count[i] << ' ' << stones[i] << '\n';
    }
    cout << '\n';
    int tmp = 2e9;
    for (int i = 0; i < count.size(); i++) {
        if (count[i] >= k && stones[i] < tmp) tmp = stones[i];
    }
    cout << tmp;
    return answer;
}

int main() {
    //vector<int> stones = { 2, 4, 5, 3, 2, 1, 4, 2, 5, 1 };
    vector<int> stones = { 2,2,2,2,2,4,4,4 };
    int k = 3;
    solution(stones, k);
    return 0;
}