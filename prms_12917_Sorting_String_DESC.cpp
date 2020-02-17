#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string asString(vector<pair<char, int>> vec) {
    string str = "";
    for (int i = 0; i < vec.size(); ++i) {
        
        str += vec[i].first;
    }
    return str;
}

bool cmpr(pair<char, int> &a, pair<char, int> &b) {
    return a.second > b.second;
}

string solution(string s) {
    string answer = "";
    vector<pair<char, int> > lower;
    vector<pair<char, int> > upper;

    for (int i = 0; i < s.size(); i++) {
        //A~Z : 65 ~ 90 , a~z : 97 ~ 122
        if (int(s.at(i)) <= 90) upper.push_back(make_pair(s[i], int(s[i])));
        else lower.push_back(make_pair(s[i], int(s[i])));

    }
    sort(upper.begin(), upper.end(), cmpr);
    sort(lower.begin(), lower.end(), cmpr);

    answer += asString(lower);
    answer += asString(upper);
    return answer;
}

int main() {
    string s = "Zbcdefg";
    solution(s);
    return 0;
}