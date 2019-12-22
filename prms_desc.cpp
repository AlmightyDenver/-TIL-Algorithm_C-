//#include <string>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//long long solution(long long n) {
//    long long answer = 0;
//    vector<int> v;
//    while (n >= 10) {
//        v.push_back(n % 10);
//        n /= 10;
//    }
//    v.push_back(n);
//
//    sort(v.begin(), v.end(), greater<int>());
//
//
//    for (int i = 0; i < v.size(); ++i) {
//        if (i >= 1) answer *= 10;
//        answer += v[i];
//    }
//    return answer;
//}
//
//int main() {
//    int n = 128372;
//    solution(n);
//    return 0;
//}