#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    for (int i = 0; i < progresses.size(); i++) {
        int tmp = 100 - progresses[i];
        
        if (tmp % speeds[i] == 0) tmp /= speeds[i];
        else {
            tmp /= speeds[i];
            tmp += 1;
        }
        q.push(tmp);
    }

    int cnt = 1;
    int last = q.front();
    q.pop();
    while (!q.empty()) {
        if (q.front() <= last) {
            q.pop();
            cnt++;
        }
        else {
            answer.push_back(cnt);
            cnt =0;
            last = q.front();
        }
    }
    answer.push_back(cnt);

    return answer;
}

int main() {
    vector<int> progresses = {93,30,55, 10, 10 ,50};
    vector<int> sp = { 1,30,5, 50,8, 50};
    solution(progresses, sp);
    return 0;
}