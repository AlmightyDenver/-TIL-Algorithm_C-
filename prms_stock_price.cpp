#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer;
	for (int i = 0; i < prices.size() - 1; ++i) {
		int cnt = 0;
		for (int j = i + 1; j < prices.size(); ++j) {
			if (prices[i] <= prices[j]) cnt++;
			else if (prices[i] > prices[j]) {
				cnt++;
				break;
			}
		}
		answer.push_back(cnt);
	}
	//마지막 원소 
	answer.push_back(0);
	return answer;
}

int main() {
	vector<int> prices = { 3, 2, 4, 4, 3 };
	vector<int> ans = solution(prices);
	return 0;
}