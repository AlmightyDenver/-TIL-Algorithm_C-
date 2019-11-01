#include <string>
#include <vector>
#include<iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int solution(vector<int> money) {
	int n = money.size();
	int arr[n];
	int arr2[n];
	std::fill_n(arr, n + 1, -1);
	std::fill_n(arr2, n + 1, -1);

	arr[0] = money[0];
	arr[1] = money[1];
	arr[2] = money[0] + money[2];
	//1번집부터
	for (int i = 3; i < n - 1; i++) { //4번집 ~ 마지막-1번집
		if (arr[i] == -1) arr[i] = money[i] + (arr[i - 2] > arr[i - 3] ? arr[i - 2] : arr[i - 3]);
	}
	//2번집부터
	arr2[0] = 0;
	arr2[1] = money[1];
	arr2[2] = money[2];
	for (int j = 3; j < n; j++) {
		arr2[j] = money[j] + (arr2[j - 2] > arr2[j - 3] ? arr2[j - 2] : arr2[j - 3]);
		//비교후 큰 값 저장
		arr[j] = arr[j] > arr2[j] ? arr[j] : arr2[j];
	}
	int mx = 0;
	if (n > 5) {
		for (int k = n - 3; k < n; k++) {
			if (mx < arr[k]) mx = arr[k];
		}
	}
	else {
		for (int k = 1; k < n; k++) {
			if (mx < arr[k]) mx = arr[k];
		}
	}
	return mx;

}