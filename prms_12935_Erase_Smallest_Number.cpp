//https://programmers.co.kr/learn/courses/30/lessons/12935

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int mini = 2e9;
    int min_idx;

    if (arr.size() == 1) {
        answer.push_back(-1);
        return answer;
    }
    else {
        for (int i = 0; i < arr.size(); ++i) {
            if (arr[i] < mini) {
                mini = arr[i];
                min_idx = i;
            }
        }
    }
    //erase (min_idx)th element 
    arr.erase(arr.begin() + min_idx);
    return arr;
}

int main() {
    vector<int> arr = { 4,3,2,1 };
    solution(arr);
    return 0;
}