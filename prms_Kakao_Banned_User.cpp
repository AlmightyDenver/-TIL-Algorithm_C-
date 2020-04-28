#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
using namespace std;
bool check[8];
int blen, ulen;
set<string> s;

//combi : ���� string���� ��Ÿ�� ��

void dfs(int idx, string combi, vector<string> user_id, vector<string>banned_id) {
    if (idx == banned_id.size()) {
        sort(combi.begin(), combi.end());
        s.insert(combi);
        return;
    }

    for (int i = 0; i < user_id.size(); i++) {
        if(user_id[i].size() != banned_id[idx].size()) continue; //���� �ٸ���
        if (check[i]) continue; //�̹� �ٸ� banned_id�� ���ε� �ָ�

        //���� �ܾ����� Ȯ��
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
            //user_id[i] �� banned[idx] �� ���ε�, ���� �ҷ� ���̵� Ž��
            dfs(idx + 1, combi + to_string(i), user_id, banned_id);
            //banned[idx]�� ���ε� �� �ִ� �ٸ� user_id ã������ flase�� üũ
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