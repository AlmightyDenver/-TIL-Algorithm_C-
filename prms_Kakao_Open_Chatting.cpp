#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;


vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> m; //uid nick
    vector<pair<string, string> > statusVec; //uid, status

    for (int i = 0; i < record.size(); i++) {
        string uid = "";
        string status;
        string nick = "";
        status = record[i][0];
        
        //id 인덱스찾기
        int idx_start = -1;
        int idx_end = 0;
        for (int j = 0; j < record[i].size(); j++) {
            if (record[i][j] == ' ' ){
                if (idx_start == -1) {
                    idx_start = j + 1;
                    if (status == "L") {
                        idx_end = record[i].size();
                        break;
                    }
                }
                else {
                    idx_end = j;
                    break;
                }
            }
            
        }
        uid = record[i].substr(idx_start, idx_end-idx_start);
        if (status != "L") nick = record[i].substr(idx_end +1, record[i].size() - (idx_end+1));

        if (status == "C") m[uid] = nick;
        //else if (status == "E" && m.find(uid) != m.end())  m[uid] = nick;
        else {
            statusVec.push_back(make_pair(uid, status));
            if(status != "L") m[uid] = nick;
        }
    }


    for (int i = 0; i < statusVec.size(); i++) {
        string str = "";
        str += m[statusVec[i].first] + "님이 ";
        if (statusVec[i].second == "E") str += "들어왔습니다.";
        else str += "나갔습니다.";
        answer.push_back(str);
    }
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << '\n';
    }
    return answer;
}

int main() {
    vector<string> record;
    //record = { "Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan" };
    //record = { "Enter uid1234 Muzi","Leave uid1234", "Enter uid1234 Ryan", "Change uid1234 Prodo" };
    //record = { "Enter uid1234 Muzi","Change uid1234 Prodo" ,"Enter uid8888 Muzi", "Leave uid1234", "Enter uid1234 Ryan", "Change uid8888 Prodo", "Change uid8888 Keykey","Enter uid5555 Key" , "Enter uid123 Key","Change uid123 Den", "Leave uid123","Leave uid1234" };
    //record = { "Enter uid1234 Muzi","Enter uid8888 Muzi", "Enter uid1234 Ryan", "Enter uid5555 Key" , "Enter uid123 Key", "Leave uid123","Leave uid1234" };
    record = { "Enter u1234 Muzi","Change u1234 COCO", "Enter u12345 Den", "Change u12345 Ryon" , "Change u12345 Den", "Change u12345 D", "Enter uid123 brother", "Leave uid123"};
    solution(record);
    return 0;
}