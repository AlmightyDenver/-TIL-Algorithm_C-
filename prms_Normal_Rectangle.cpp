#include <iostream>

using namespace std;

//a가 큰수
long long calc_g(long long a, long long b) {
	int g = b;
	while (g > 1) {
		if (a % g == 0 && b%g == 0) {
			break;
		}
		else g--;
	}
	return g;
}

long long solution(int w, int h)
{
	long long answer = (long long)w * (long long)h;
	//공약수 구하기
	long long g = 0;
	if (w == h) {
		answer -= w;
		return answer;
	}
	else if (w < h) g = calc_g(h, w);
	else g = calc_g(w, h);

	answer -= (w + h - g);
	return answer;

}
