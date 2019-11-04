///* 블로그 참고 https://tallman.tistory.com/7 */
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
//	//visit 초기화
//	for (i = 0; i < MAX; i++) {
//		visit[i] = 0;
//	}
//
//	for (i = 0; i < size; i++) {
//		if (visit[i] == 1) continue;
//		//종류 같은 옷 만나면 a[i]++
//		for (int j = i; j < size; j++) {
//			if (clothes[i][1] == clothes[j][1]) {
//				a[i]++;
//				visit[j] = 1;
//			}
//		}
//	}
////(옷1의수 +1)(옷2의수+1)... -1
//	for (i = 0; i < MAX; i++) {
//		if (a[i] > 0) ret *= (a[i] + 1);
//	}
//	answer = ret - 1;
//	return answer;
//}