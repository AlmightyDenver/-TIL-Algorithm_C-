#include <string>
#include <vector>
#include <queue>

using namespace std;

priority_queue<int> pq;
queue<int> q;


int solution(vector<int> priorities, int location) {
    int answer = 0;
    for (int i = 0; i < priorities.size(); i++) {
        pq.push(priorities[i]);
    }
    int order = 0;
    int idx = 0;
    while (!pq.empty()) {
        for (int i = idx; i < priorities.size(); i++) {
            if (priorities[i] == pq.top()) {
                if (i == location) return order+1;
                order++;
                idx = i + 1;
                priorities[i] = 0;
            }
        }
        if (idx != 0) {
            for (int i = 0; i < idx; i++) {
                if (priorities[i] == pq.top()) {
                    if (i == location) return order+1;
                    order++;
                    idx = i + 1;
                    priorities[i] = 0;
                }
            }
        }
        pq.pop();
    }
}

int main() {
    //vector<int> priorities = {2, 1, 3, 2 };
    //vector<int> priorities = { 1, 1, 9, 1, 1, 1 };
    vector<int> priorities = { 2,2,2,1,3,4 };
    int location = 3;
    cout << solution(priorities, location) << '\n';
    return 0;
}