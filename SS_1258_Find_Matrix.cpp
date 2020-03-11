#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int map[101][101];
bool visit[101][101] = { false, };
vector < pair<int, pair<int, int>>> vec;

bool cmpr(pair<int, pair<int, int> >& a, pair<int, pair<int, int> >& b) {
	if (a.first == b.first) return a.second.first < b.second.first;
	return a.first < b.first;
}

void DFS(int y, int x) {
	visit[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (!visit[ny][nx] && map[ny][nx] != 0) {
			DFS(ny, nx);
		}
	}
}


int main(int argc, char** argv) {
	int test_case;
	int T;
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N;
		
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}

		//solve
		int cnt_matrix = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] != 0 && !visit[i][j]) {
					cnt_matrix++;
					int cnt_r = 1;
					int cnt_c = 1;
					DFS(i, j);
					while (true) {
						if (map[i + cnt_c][j] == 0) break;
						else {
							cnt_c++;
						}

					}
					while (true) {
						if (map[i][j + cnt_r] == 0) break;
						else {
							cnt_r++;
						}
					}
					vec.push_back(make_pair(cnt_c * cnt_r, make_pair(cnt_c, cnt_r)));
				}
			}
		}

		sort(vec.begin(), vec.end(), cmpr);
		cout << '#' << test_case << ' ';
		cout << vec.size() << ' ';
		for (int i = 0; i < vec.size(); i++) {
			cout << vec[i].second.first << ' ' << vec[i].second.second << ' ';
		}


		//init
		cout << '\n';
		vec.clear();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				map[i][j] = 0;
				visit[i][j] = false;
			}
		}
	}
	return 0;
}