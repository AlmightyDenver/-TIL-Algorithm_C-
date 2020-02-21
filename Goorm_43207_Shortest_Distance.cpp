#include <iostream>
#include <algorithm>
using namespace std;
#include <iostream>
#include <algorithm>
using namespace std;
int N;
int arr[1000000];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	int mini = 2e9;
	for (int i = 1; i < N; i++) {
		int diff = arr[i] - arr[i - 1];
		if (diff < mini) mini = diff;
	}
	cout << mini << '\n';
	return 0;
}