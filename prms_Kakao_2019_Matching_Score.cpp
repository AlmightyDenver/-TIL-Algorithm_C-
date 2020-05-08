#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;


vector<string> tokenize(string str, const char*& delimiters) {
    vector<string> vec;
    char* str_buff = new char[1510];
    strcpy(str_buff, str.c_str());
    char* tok = strtok(str_buff, delimiters);
    while (tok != nullptr) {
        vec.push_back((string)tok);
        tok = strtok(nullptr, delimiters);
    }
    return vec;
}

int solution(string word, vector<string> pages) {
    int answer = 0;
    const char* delimiters;
    vector<string> links; //page의 링크
    vector<int> basics; //basic score
    map<string, double> m; //page의 링크, 링크점수

    for (int i = 0; i < pages.size(); ++i) {

        //기본점수 
        int basic_score = 0;
        delimiters = "0123456789`~!@#$%^&*()_+=-[]\{}|;':\",./<>?\n\t ";
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        vector<string> words_vec = tokenize(pages[i], delimiters);
        for (int j = 0; j < words_vec.size(); j++) {
            transform(words_vec[j].begin(), words_vec[j].end(), words_vec[j].begin(), ::tolower);
            if (words_vec[j] == word) basic_score++;
        }
        basics.push_back(basic_score);

        //외부 링크 수, 자신 링크
        delimiters = "<>\n\\";
        vector<string> tag_vec = tokenize(pages[i], delimiters);
        string myLink = "";
        vector<string> ext_link;
        for (int j = 0; j < tag_vec.size(); j++) {
            string slice = tag_vec[j].substr(0, 4);
            //자신 링크
            if (slice == "meta") {
                size_t pos = tag_vec[j].find("https://");
                if (pos != string::npos) {
                    myLink = tag_vec[j].substr(pos + 8);
                }
                else {
                    pos = tag_vec[j].find("http://");
                    if (pos != string::npos) {
                        myLink = tag_vec[j].substr(pos + 7);
                    }
                }
                if (myLink.size() != 0) {
                    for (int k = myLink.size() - 4; k < myLink.size(); k++) {
                        if (myLink[k] == '\"' || myLink[k] == '/' || myLink[k] == '\\') myLink = myLink.substr(0, k);
                    }
                    m.insert(make_pair(myLink, 0));
                    links.push_back(myLink);
                }
            }
            //외부 링크
            else if (slice == "a hr") {
                string tmp = tag_vec[j].substr(16);
                for (int k = tmp.size() - 4; k < tmp.size(); k++) {
                    if (tmp[k] == '\"' || tmp[k] == '/' || tmp[k] == '\\') tmp = tmp.substr(0, k);
                }
                ext_link.push_back(tmp);
            }
        }
        ext_link.erase(unique(ext_link.begin(), ext_link.end()), ext_link.end());
        //외부 링크 수
        int ext_score = ext_link.size();
        //링크 점수 더해준다
        double myLinkScore = basic_score / (double)ext_score;
        for (int j = 0; j < ext_link.size(); j++) {
            m[ext_link[j]] += myLinkScore;
        }
    }

    //링크점수 구해서 max의 idx 구하기
    double maxi = 0;
    for (int i = 0; i < links.size(); ++i) {
        if (maxi < m[links[i]] + basics[i]) {
            maxi = m[links[i]] + basics[i];
            answer = i;
        }
    }
    return answer;
}

int main() {
    string word;
    vector<string> pages;
    word = "Muzi";
    pages = { "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://careers.kakao.com/interview/list\"/>\n</head>  \n<body>\n<a href=\"https://programmers.co.kr/learn/courses/4673\"></a>#!MuziMuzi!)jayg07con&&\n\n</body>\n</html>",
        "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://www.kakaocorp.com\"/>\n</head>  \n<body>\ncon%\tmuzI92apeach&2<a href=\"https://hashcode.co.kr/tos\"></a>\n\n\t^\n</body>\n</html>" };
    //pages = { "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://a.com\"/>\n</head>  \n<body>\nBlind Lorem Blind ipsum dolor Blind test sit amet, consectetur adipiscing elit. \n<a href=\"https://b.com\"> Link to b </a>\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://b.com\"/>\n</head>  \n<body>\nSuspendisse potenti. Vivamus venenatis tellus non turpis bibendum, \n<a href=\"https://a.com\"> Link to a </a>\nblind sed congue urna varius. Suspendisse feugiat nisl ligula, quis malesuada felis hendrerit ut.\n<a href=\"https://c.com\"> Link to c </a>\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://c.com\"/>\n</head>  \n<body>\nUt condimentum urna at felis sodales rutrum. Sed dapibus cursus diam, non interdum nulla tempor nec. Phasellus rutrum enim at orci consectetu blind\n<a href=\"https://a.com\"> Link to a </a>\n</body>\n</html>" };
    //word = "blind";
    solution(word, pages);
    return 0;
}