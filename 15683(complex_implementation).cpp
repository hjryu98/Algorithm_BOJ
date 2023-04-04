#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
1�� 4�� ����
2�� 2�� ����
3�� 4�� ����
4�� 4�� ����
5�� �� ������ ��(�״�� 1��)
*/
int n, m, ans = 999999999, cnt;
int arr[10][10];
int dir[10]; // cctv�� ���� ������ �����ϴ� �迭, ������ �б��ؼ� �����ϱ�
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
vector <pair<pair<int, int>, int>> cctv;

bool range(int x, int y) {
	return x >= 0 && x < n&& y >= 0 && y < m;
}

void solve() {
	bool check[10][10] = { 0, }; // true��� �̰��� �簢���밡 �ƴ�.
	int size = cctv.size();
	int sum = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] != 0) check[i][j] = true;
		}
	}

	for (int i = 0; i < size; i++) {
		int cx = cctv[i].first.first;
		int cy = cctv[i].first.second;

		if (cctv[i].second == 5) {
			for (int j = 0; j < 4; j++) {
				cx = cctv[i].first.first;
				cy = cctv[i].first.second;
				int nx = cx + dx[j];
				int ny = cy + dy[j];

				while (arr[nx][ny] != 6 && range(nx, ny)) {
					check[nx][ny] = true;
					cx += dx[j];
					cy += dy[j];
					nx = cx + dx[j];
					ny = cy + dy[j];
				}
			}
		}

		else if (cctv[i].second == 2) {
			if (dir[i] == 0) {
				for (int j = 0; j < 4; j += 2) {
					cx = cctv[i].first.first;
					cy = cctv[i].first.second;
					int nx = cx + dx[j];
					int ny = cy + dy[j];

					while (arr[nx][ny] != 6 && range(nx, ny)) {
						check[nx][ny] = true;
						cx += dx[j];
						cy += dy[j];
						nx = cx + dx[j];
						ny = cy + dy[j];
					}
				}
			}

			else {
				for (int j = 1; j < 4; j += 2) {
					cx = cctv[i].first.first;
					cy = cctv[i].first.second;
					int nx = cx + dx[j];
					int ny = cy + dy[j];

					while (arr[nx][ny] != 6 && range(nx, ny)) {
						check[nx][ny] = true;
						cx += dx[j];
						cy += dy[j];
						nx = cx + dx[j];
						ny = cy + dy[j];
					}
				}
			}
		}

		else {
			if (cctv[i].second == 1) {
				cx = cctv[i].first.first;
				cy = cctv[i].first.second;
				int nx = cx + dx[dir[i]];
				int ny = cy + dy[dir[i]];

				while (arr[nx][ny] != 6 && range(nx, ny)) {
					check[nx][ny] = true;
					cx += dx[dir[i]];
					cy += dy[dir[i]];
					nx = cx + dx[dir[i]];
					ny = cy + dy[dir[i]];
				}
			}

			else if (cctv[i].second == 3) {
				int odir = (dir[i] + 1) % 4;

				cx = cctv[i].first.first;
				cy = cctv[i].first.second;
				int nx = cx + dx[dir[i]];
				int ny = cy + dy[dir[i]];

				while (arr[nx][ny] != 6 && range(nx, ny)) {
					check[nx][ny] = true;
					cx += dx[dir[i]];
					cy += dy[dir[i]];
					nx = cx + dx[dir[i]];
					ny = cy + dy[dir[i]];
				}

				cx = cctv[i].first.first;
				cy = cctv[i].first.second;
				nx = cx + dx[odir];
				ny = cy + dy[odir];

				while (arr[nx][ny] != 6 && range(nx, ny)) {
					check[nx][ny] = true;
					cx += dx[odir];
					cy += dy[odir];
					nx = cx + dx[odir];
					ny = cy + dy[odir];
				}
			}

			else {
				cx = cctv[i].first.first;
				cy = cctv[i].first.second;
				int nx = cx + dx[dir[i]];
				int ny = cy + dy[dir[i]];

				while (arr[nx][ny] != 6 && range(nx, ny)) {
					check[nx][ny] = true;
					cx += dx[dir[i]];
					cy += dy[dir[i]];
					nx = cx + dx[dir[i]];
					ny = cy + dy[dir[i]];
				}

				for (int j = 0; j < 4; j++) {
					if (dir[i] == 0 || dir[i] == 2) {
						if (j == 0 || j == 2) continue;
						cx = cctv[i].first.first;
						cy = cctv[i].first.second;
						nx = cx + dx[j];
						ny = cy + dy[j];

						while (arr[nx][ny] != 6 && range(nx, ny)) {
							check[nx][ny] = true;
							cx += dx[j];
							cy += dy[j];
							nx = cx + dx[j];
							ny = cy + dy[j];
						}
						cx = cctv[i].first.first;
						cy = cctv[i].first.second;
						nx = cx + dx[j];
						ny = cy + dy[j];

						while (arr[nx][ny] != 6 && range(nx, ny)) {
							check[nx][ny] = true;
							cx += dx[j];
							cy += dy[j];
							nx = cx + dx[j];
							ny = cy + dy[j];
						}
					}

					else if (dir[i] == 1 || dir[i] == 3) {
						if (j == 1 || j == 3) continue;
						cx = cctv[i].first.first;
						cy = cctv[i].first.second;
						nx = cx + dx[j];
						ny = cy + dy[j];

						while (arr[nx][ny] != 6 && range(nx, ny)) {
							check[nx][ny] = true;
							cx += dx[j];
							cy += dy[j];
							nx = cx + dx[j];
							ny = cy + dy[j];
						}
						cx = cctv[i].first.first;
						cy = cctv[i].first.second;
						nx = cx + dx[j];
						ny = cy + dy[j];

						while (arr[nx][ny] != 6 && range(nx, ny)) {
							check[nx][ny] = true;
							cx += dx[j];
							cy += dy[j];
							nx = cx + dx[j];
							ny = cy + dy[j];
						}
					}
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!check[i][j]) sum++;
		}
	}
	ans = min(ans, sum);
}

void recur(int cur) { // ���� �Ǵ��ϴ� cctv�� ��°
	if (cur >= cctv.size()) {
		solve();
		return;
	}

	if (cctv[cur].second == 2) {
		dir[cur] = 0;
		recur(cur + 1);
		dir[cur] = 1;
		recur(cur + 1);
	}

	else if (cctv[cur].second == 5) {
		dir[cur] = 0;
		recur(cur + 1);
	}

	else {
		for (int i = 0; i < 4; i++) {
			dir[cur] = i;
			recur(cur + 1);
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] >= 1 && arr[i][j] <= 5) {
				cctv.push_back({ {i,j}, arr[i][j] });
			}
			else if (arr[i][j] == 0) cnt++;
		}
	}

	recur(0);
	cout << ans;

	return 0;
}