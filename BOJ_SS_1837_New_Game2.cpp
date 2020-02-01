//#include <iostream>
//#include <vector>
//#include <deque>
//
//using namespace std;
//
//int N, K;
//int map[12][12];
//
////�� ĭ�� �� ���� �ִ���
//typedef deque<int> dq;
//dq visit[12][12];
////�� ��ġ, ���� ���� <<x, y> dir>
//typedef pair<pair<int, int>, int> pr;
//pr piece[12];
//int dx[4] = { 0,0,-1,1 };
//int dy[4] = { 1,-1,0,0 };
//
//void white(int i, int curr_x, int curr_y, int nx, int ny) {
//	dq tmp_dq;
//	//�ڱⰡ �� �Ʒ��� �ƴ϶�� : �ؿ��ִ¾ֵ�  tmp_dq�� �ǽ�
//	while (!visit[curr_x][curr_y].empty() && visit[curr_x][curr_y].front() != i) {
//		tmp_dq.push_back(visit[curr_x][curr_y].front());
//		visit[curr_x][curr_y].pop_front();
//	}
//	//�ڱ� ���� ������ �ű��
//	while (!visit[curr_x][curr_y].empty()) {
//		int p = visit[curr_x][curr_y].front();
//		int d = piece[p].second;
//		piece[p] = make_pair(make_pair(nx, ny), d);
//		visit[nx][ny].push_back(p);
//		visit[curr_x][curr_y].pop_front();
//	}
//	//tmp_dq ���ڸ���
//	visit[curr_x][curr_y].swap(tmp_dq);
//}
//
//void red(int i, int curr_x, int curr_y, int nx, int ny) {
//	//�ڱ� ���� �ִ¾ֵ� ���� �ű��
//	while (visit[curr_x][curr_y].back() != i) {
//		int p = visit[curr_x][curr_y].back();
//		int d = piece[p].second;
//		//�ű� ĭ�� �ױ�
//		visit[nx][ny].push_back(p);
//		//piece�� ���� ����
//		piece[visit[curr_x][curr_y].back()] = make_pair(make_pair(nx, ny), d);
//		//�ִ��ڸ����� pop
//		visit[curr_x][curr_y].pop_back();
//	}
//	//�ڱⰡ �� ����
//	visit[nx][ny].push_back(visit[curr_x][curr_y].back());
//	piece[visit[curr_x][curr_y].back()] = make_pair(make_pair(nx, ny), piece[visit[curr_x][curr_y].back()].second);
//	visit[curr_x][curr_y].pop_back();
//}
//
//
//void check_colour(int i, int curr_x, int curr_y, int nx, int ny) {
//	if (nx < 0 || ny < 0 || nx >= N || ny >= N || map[nx][ny] == 2) {
//		//���� �ٲٱ�
//		if (piece[i].second == 0 || piece[i].second == 2) piece[i].second++;
//		else piece[i].second--;
//		//�ٲ� ���� ���� �ڸ� ���� Ȯ��
//		nx = curr_x + dx[piece[i].second];
//		ny = curr_y + dy[piece[i].second];
//		if (map[nx][ny] != 2) check_colour(i, curr_x, curr_y, nx, ny);
//	}
//	else if (map[nx][ny] == 1) red(i, curr_x, curr_y, nx, ny);
//	else white(i, curr_x, curr_y, nx, ny);
//}
//
//void solve() {
//	int cnt = 0;
//	//1000������ ũ�ų� �ȵǸ�
//	while (cnt < 1000) {
//		cnt++;
//		for (int i = 0; i < K; i++) {
//			int curr_x = piece[i].first.first;
//			int curr_y = piece[i].first.second;
//			int nx = curr_x + dx[piece[i].second];
//			int ny = curr_y + dy[piece[i].second];
//			
//			check_colour(i, curr_x, curr_y, nx, ny);
//
//			//���ڸ��� ������ ������
//			if (visit[nx][ny].size() >= 4) {
//				cout << cnt << '\n';
//				return;
//			}
//			
//		}
//		
//	}
//	cout << -1 << '\n';
//	return;
//}
//
//int main() {
//	//input
//	ios::sync_with_stdio(0); cin.tie(0);
//	cin >> N >> K;
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			cin >> map[i][j];
//		}
//	}
//
//	for (int i = 0; i < K; i++) {
//		int x, y, d;
//		cin >> x >> y >> d;
//		x--;
//		y--;
//		d--;
//		piece[i] = (make_pair(make_pair(x, y), d));
//		visit[x][y].push_back(i);
//	}
//
//	//
//	solve();
//
//	return 0;
//}