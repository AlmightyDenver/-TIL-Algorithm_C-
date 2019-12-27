//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//bool compr(const pair<int, int>& a, const pair<int, int>& b) {
//    if (a.second == b.second) return a.first < b.first;
//    else return a.second > b.second;
//}
//
//vector<int> solution(vector<int> answers) {
//    vector<int> answer;
//    vector<pair<int, int>> count; //<supo, count>
//    vector<vector <int>> supos = { {1,2,3,4,5}, {2,1,2,3,2,4,2,5},{3,3,1,1,2,2,4,4,5,5} };
//    for (int i = 0; i < supos.size(); ++i) {
//        int cnt = 0;
//        for (int j = 0; j < answers.size(); ++j) {
//            if (supos[i][j % supos[i].size()] == answers[j]) cnt++;
//        }
//        count.push_back(pair<int, int> (i+1, cnt));
//    }
//    sort(count.begin(), count.end(), compr);
//    //단독 1등
//    if (count[0].second > count[1].second) answer.push_back(count[0].first);
//    else if (count[0].second == count[1].second) {
//        //공동 1등 2명
//        if (count[1].second > count[2].second) {
//            answer.push_back(count[0].first);
//            answer.push_back(count[1].first);
//   /*         sort(answer.begin(), answer.end());*/
//            //compr에서 second가 같으면 first가 작은순으로 정렬해서 불필요
//        }
//        //공동 1등 3명
//        else {
//            answer.push_back(1);
//            answer.push_back(2);
//            answer.push_back(3);
//        }
//    }
//    return answer;
//}
//
//int main() {
//    vector<int> answers = { 1,2,3,4,5 };
//    solution(answers);
//    return 0;
//}