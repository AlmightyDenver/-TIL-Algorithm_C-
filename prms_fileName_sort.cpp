#include <string>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

typedef tuple<string, int, int> tple; //head, number, index

bool oper(const tple& a, const tple& b) {
    if (get<0>(a) == get<0>(b)) {
        if ((get<1>(a) == get<1>(b))) {
            //stable sort���� ������ �ڸ� �ٲ��� ����
            return get<2>(a) < get<2>(b);
        }
        return get<1>(a) < get<1>(b);
    }
    return get<0>(a) < get<0>(b);

}


vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<tple> vec;
    for (int i = 0; i < files.size(); ++i) {
        //head, number ����(h, num)   
        string f = files[i];
        int n1 = 0;
        int n2 = 0;
        for (int j = 0; j < f.size(); j++) {
            int asci = (int)f[j];
            //head ���� �ε���
            if (n1 == 0 && asci >= 48 && asci <= 57) n1 = j;
            //number �� �ε���
            if (j > n1 && n2 == 0 && asci < 48 && asci >57) {
                n2 = j;
                break;
            }
        }
        string h = f.substr(0, n1);
        transform(h.begin(), h.end(), h.begin(), ::tolower);
        int num = stoi(f.substr(n1, n2-n1));
        tple t = make_tuple(h, num, i);
        vec.push_back(t);
    }
    sort(vec.begin(), vec.end(), oper);
    for (int i = 0; i < vec.size(); ++i) {
        answer.push_back(files[get<2>(vec[i])]);
    }
    return answer;
}

int main() {
    vector<string> files = { "img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG" };
    //vector<string> files = { "MUZI01.zip", "muzi1.png" };
    solution(files);
    return 0;
}