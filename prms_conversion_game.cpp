//#include <string>
//#include <vector>
//#include <iostream>
//using namespace std;
//
//char intToChar[17] = "0123456789ABCDEF";
//string str = "";
//
////k의 N진수 변환
//string conv(int k, int N) {
//    int q = k / N;
//    int r = k % N;
//    if (q == 0) {
//        str += intToChar[r];
//        return str;
//    }
//    conv(q, N);
//    str += intToChar[r];
//    return str;
//}
//
//string solution(int n, int t, int m, int p) {
//    string answer = "";
//
//    //진법 젼환후 담기
//    int k = 0;
//    while (str.size() < t * m) {
//        conv(k, n);
//        k++;
//    }
//
//    //튜브 차례번째 글자 담기
//    for (int i = 0; i < t; i++) {
//        answer += str[(p - 1) + (m * i)];
//    }
//    return answer;
//}
//
//int main() {
//    int n = 16;
//    int t = 16;
//    int m = 2;
//    int p = 2;
//    solution(n, t, m, p);
//    return 0;
//}