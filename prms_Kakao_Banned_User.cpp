#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
using namespace std;
bool check[8];
int blen, ulen;
set<string> s;

//combi : 조합 string으로 나타낸 것

void dfs(int idx, string combi, vector<string> user_id, vector<string>banned_id) {
    if (idx == banned_id.size()) {
        sort(combi.begin(), combi.end());
        s.insert(combi);
        return;
    }

    for (int i = 0; i < user_id.size(); i++) {
        if(user_id[i].size() != banned_id[idx].size()) continue; //길이 다르면
        if (check[i]) continue; //이미 다른 banned_id와 매핑된 애면

        //제제 단어인지 확인
        bool flag = true;
        for (int j = 0; j < banned_id[idx].size(); j++) {
            if (banned_id[idx][j] == '*') continue;
            if (user_id[i][j] != banned_id[idx][j]) {
                flag = false;
                break;
            }
        }

        if (flag) {
            check[i] = true;
            //user_id[i] 는 banned[idx] 와 매핑됨, 다음 불량 아이디 탐색
            dfs(idx + 1, combi + to_string(i), user_id, banned_id);
            //banned[idx]와 매핑될 수 있는 다른 user_id 찾기위해 flase로 체크
            check[i] = false;
        }

    }

}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;

    dfs(0, "", user_id, banned_id);
    answer = s.size();
    cout << answer;
    return answer;
}

int main() {
    vector<string> user_id = {"frodo", "fradi", "crodo", "abc123", "frodoc"};
    vector<string> banned_id = {"fr*d*", "abc1**" };
    solution(user_id, banned_id);
    return 0;
}