#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(vector<vector<int> > v) {
    vector<int> ans;
    int x1, x2, y1, y2;
    x1 = v[0][0];
    y1 = v[0][1];
    x2 = v[1][0];
    y2 = v[1][1];
    if (v[2][0] == x1) ans.push_back(x2);
    else if (v[2][0] == x2) ans.push_back(x1);
    else ans.push_back(v[2][0]);

    if (v[2][1] == y1) ans.push_back(y2);
    else if (v[2][1] == y2) ans.push_back(y1);
    else ans.push_back(v[2][1]);

    return ans;
}