//#include <iostream>
//#include <stdio.h>
//#include <string>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int solution(vector<int> d, int budget) {
//    int answer = 0;
//    sort(d.begin(), d.end());
//    int sum = 0;
//    int cnt = 0;
//    for (int i = 0; i < d.size(); ++i) {
//        if ((sum += d[i]) <= budget) {
//            cnt += 1;
//        }
//        else break;
//    }
//    answer = cnt;
//    cout << answer;
//    return answer;
//}
//
//int main() {
//    vector<int> d = { 2,2,3,3 };
//    int b = 10;
//    solution(d, b);
//    return 0;
//}