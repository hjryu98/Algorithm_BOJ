#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <iostream>
#include <queue>
#include <algorithm> /////1245
using namespace std;
int n, m;
int cnt;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int arr[105][75];
bool check[105][75];
queue <pair<int, int>> q;

bool range(int x, int y) {
	return x >= 0 && x < n&& y >= 0 && y < m;
}

void bfs(int x, int y) {
	check[x][y] = true;
	q.push({ x,y });

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		int cur = arr[cx][cy];

		q.pop();

		bool flag = true;

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (range(nx, ny) && !check[nx][ny]) {
				if (cur <= arr[nx][ny]) flag = false;

				if (arr[nx][ny] > 0) {
					q.push({ nx,ny });
					check[nx][ny] = true;
				}
			}
		}
		if (flag) cnt++;
	}
}


int main() {
	fastio;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cin >> arr[i][j];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!check[i][j] && arr[i][j] > 0) {
				bfs(i, j);
			}
		}
	}
	cout << cnt;

	return 0;
}