//#include <string>
//#include <vector>
//#include <iostream>
//using namespace std;
//
//int solution(int num) {
//    long long n = num;
//    int answer = -1;
//    int cnt = 0;
//    while (cnt < 500 && n != 1) {
//        if (n % 2 == 0) {
//            n /= 2;
//            cnt += 1;
//        }
//        else {
//            n *= 3;
//            n += 1;
//            cnt += 1;
//        }
//    }
//    if (cnt < 500) answer = cnt;
//    cout << answer;
//    return answer;
//}
//
//int main() {
//    //int n = 6;
//    int n = 626331;
//    solution(n);
//    return 0;
//}