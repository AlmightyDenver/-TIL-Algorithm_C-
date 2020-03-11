#include <iostream>

using namespace std;


int main(int argc, char** argv)
{
	ios::sync_with_stdio(0); cin.tie(0);
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N;
		int u, v;
		int arr[10000] = { 0, };
		bool memo[10000] = { false, };

		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> u >> v;
			arr[u] = v;
			memo[v] = true;
		}

		//암나사가 없는애가 시작점
		int start = 0;
		for (int i = 0; i < 1000; i++) {
			if (arr[i] != 0 && !memo[i]) {
				start = i;
				break;
			}
		}


		cout << '#' << test_case << ' ';
		int cnt = 0;
		while (true) {
			cout << start << ' ' << arr[start] << ' ';
			start = arr[start];
			cnt++;
			if (arr[start] == 0) break;
		}
		cout << '\n' << N << ' ' << cnt <<'\n';
	}
	return 0;
}#include <iostream>

using namespace std;


int main(int argc, char** argv)
{
	ios::sync_with_stdio(0); cin.tie(0);
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N;
		int u, v;
		int arr[10000] = { 0, };
		bool memo[10000] = { false, };

		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> u >> v;
			arr[u] = v;
			memo[v] = true;
		}

		//암나사가 없는애가 시작점
		int start = 0;
		for (int i = 0; i < 1000; i++) {
			if (arr[i] != 0 && !memo[i]) {
				start = i;
				break;
			}
		}


		cout << '#' << test_case << ' ';
		int cnt = 0;
		while (true) {
			cout << start << ' ' << arr[start] << ' ';
			start = arr[start];
			cnt++;
			if (arr[start] == 0) break;
		}
		cout << '\n' << N << ' ' << cnt <<'\n';
	}
	return 0;
}