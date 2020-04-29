#include <string>
#include <vector>
#include <map>
using namespace std;
map<long , long> m;

long long findd(long long idx) {
    if (!m[idx]) return idx;
    else if (m[idx] == 0) return idx;
    return m[idx] = findd(m[idx]);
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    for (int i = 0; i < room_number.size(); i++) {
        long long room = room_number[i];
        if (!m[room]) {
            answer.push_back(room);
            m[room] = findd(room + 1);
        }
        else {
            long long tmp = findd(room);
            answer.push_back(tmp);
            m[tmp] = findd(tmp+1);
        }

    }
    return answer;
}

int main() {
    long long k = 10;
    vector<long long> room_number = { 1,3,4,1,3,1 };
    solution(k, room_number);
    return 0;
}