#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmpr(pair<double, int> a, pair<double, int> b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    sort(stages.begin(), stages.end());
    vector<pair<double, int>> f_rate;
    

    for (int i = 1; i <= N; ++i) {
        int cnt = 0;
        double usr = 0;
        double rate = 0;
        for (int j = 0; j < stages.size(); ++j) {
            if (stages[j] == i) cnt++;
            if (stages[j] >= i) usr++;
        }

        if (cnt == 0 || usr == 0) rate = 0;
        else rate = (cnt / usr);
        f_rate.push_back(make_pair(rate, i));
    }
    sort(f_rate.begin(), f_rate.end(), cmpr);
    for (int i = 0; i < f_rate.size(); ++i) {
        answer.push_back(f_rate[i].second);
    }
  
    return answer;
}

int main() {
    int N;
    vector<int> stages;
    //N= 5;
    //stages = { 2, 1, 2, 6, 2, 4, 3, 3 };
    N = 4;
    stages = { 4,4,4,4,4 };
    solution(N, stages);
    return 0;
}