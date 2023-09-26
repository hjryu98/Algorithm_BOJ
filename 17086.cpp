#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
/*
17086
max 2 * 10^8
time complexity 50 * 50 * 50 * 50 
*/
int n, m, ans;
int arr[52][52];
queue <pair<int, int>> q;
bool check[52][52] = { 0, };
int dx[] = { 0,0,-1,1,1,-1,-1,1 };
int dy[] = { 1,-1,0,0,1,1,-1,-1 };

bool range(int x, int y) {
	return x >= 0 && x < n&& y >= 0 && y < m;
}

void bfs(int x, int y) {

	q.push({ x, y });
	check[x][y] = true;
	int dist = 0;
	while (!q.empty()) {
		int size = q.size();

		while (size--) {
			int cx = q.front().first;
			int cy = q.front().second;

			q.pop();

			if (arr[cx][cy] == 1) {
				ans = max(ans, dist);
				return;
			}

			for (int i = 0; i < 8; i++) {
				int nx = cx + dx[i];
				int ny = cy + dy[i];

				if (!range(nx, ny)) continue;

				if (check[nx][ny]) continue;

				q.push({ nx,ny });
				check[nx][ny] = true;
			}
		}
		dist++;
	}
}

void init() {
	memset(check, false, sizeof(check));
	while (!q.empty()) q.pop();
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cin >> arr[i][j];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0) {
				bfs(i, j);
				init();
			}
		}
	}
	cout << ans;

	return 0;
}