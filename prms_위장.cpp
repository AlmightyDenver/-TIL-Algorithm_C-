///* ��α� ���� https://tallman.tistory.com/7 */
//
//#include <string>
//#include <vector>
//
//#define MAX 31
//
//using namespace std;
//
//int a[MAX] = { 0,  };
//int visit[MAX];
//
//int solution(vector<vector<string>> clothes) {
//	int answer = 0;
//	int size = clothes.size();
//	int ret = 1;
//	int i;
//	//visit �ʱ�ȭ
//	for (i = 0; i < MAX; i++) {
//		visit[i] = 0;
//	}
//
//	for (i = 0; i < size; i++) {
//		if (visit[i] == 1) continue;
//		//���� ���� �� ������ a[i]++
//		for (int j = i; j < size; j++) {
//			if (clothes[i][1] == clothes[j][1]) {
//				a[i]++;
//				visit[j] = 1;
//			}
//		}
//	}
////(��1�Ǽ� +1)(��2�Ǽ�+1)... -1
//	for (i = 0; i < MAX; i++) {
//		if (a[i] > 0) ret *= (a[i] + 1);
//	}
//	answer = ret - 1;
//	return answer;
//}