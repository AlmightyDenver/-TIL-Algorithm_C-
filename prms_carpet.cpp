#include <string>
#include <vector>
#include <cmath> //pow
using namespace std;

vector<int> solution(int brown, int red) {
	vector<int> answer;
	if (red == 2) {
		answer = { 4,3 };
		return answer;
	}
	else if (red == 1) {
		answer = { 3,3 };
		return answer;
	}

	int r = red;
	for (int i = 2; i <= pow(r, 0.5); i++) {
		int box;
		if ((r % i) == 0) box = i * 2 + r / i * 2 + 4;
		if (brown == box) {
			answer.push_back(r / i + 2);
			answer.push_back(i + 2);
			break;
		}
	}
	return answer;
}