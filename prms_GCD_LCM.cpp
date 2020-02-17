#include <string>
#include <vector>

using namespace std;

int gcd(int n, int m) {
    int g = m;
    while (g > 1) {
        if (n % g == 0 && m % g == 0) {
            break;
        }
        g--;
    }
    return g;
}

vector<int> solution(int n, int m) {
    vector<int> answer;
    //n이 더 큰 수
    if (m > n) {
        int tmp = m;
        m = n;
        n = tmp;
    }
    int g = gcd(n, m);
    answer.push_back(g);
    int l = n / g * m / g * g;
    answer.push_back(l);

    return answer;
}