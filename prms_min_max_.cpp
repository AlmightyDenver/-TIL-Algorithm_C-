//#include <algorithm>
//#include <string>
//#include <vector>
//using namespace std;
//
//string solution(string s) {
//	int pos;
//	vector<int> vec;
//	//s�� ���� ���������� �ݺ�
//	while ((pos = s.find(" ")) != -1) {
//		//���� ã�Ƽ� (s�� 0~����ձ���) int ��ȯ��vec�� �߰�
//		vec.push_back(stoi(s.substr(0, pos)));
//
//		//����, ���� �κ� �ڸ���
//		if (s.size() > 1) s = s.substr(pos+1);
//		else s = "";
//	}
//	//������ ���� �߰�
//	vec.push_back(stoi(s));
//	int mini = *min_element(vec.begin(), vec.end());
//	int maxi = *max_element(vec.begin(), vec.end());
//	return to_string(mini) + " " + to_string(maxi);
//}
//
//int main() {
//	string s = "-4 12 -3 -2 10";
//	cout << solution(s);
//	return 0;
//}