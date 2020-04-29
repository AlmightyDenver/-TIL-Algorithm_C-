#include <string>
#include <vector>
using namespace std;
int parent[1000001];

int Find(int x) {
	if (x == parent[x]) {
		return x;
	}
	else {
		int y = Find(parent[x]);
		parent[x] = y;
		return y;
	}
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	parent[x] = y;

}



vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
	// 배열 생성 및 초기화
	// 처음에는 자기 자신이 부모이다 -> 모두 떨어져있기 때문
	for (int i = 0; i <= k; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < room_number.size(); i++) {
		int room = room_number[i];
		while(Find(room) != room) {
			room++;
		}
		//빈방 찾았으면
		answer.push_back(room);
		Union(room, room + 1);
	}
    return answer;
}

int main() {
    long long k = 10;
    vector<long long> room_number = { 1,3,4,1,3,1 };
    solution(k, room_number);
    return 0;
}