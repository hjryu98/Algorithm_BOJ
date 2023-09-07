#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int n;
queue <pair<int, int>> q;
bool check[102][102];
string arr[102];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int cnt1, cnt2;

void init() {
	while (!q.empty()) q.pop();
	memset(check, false, sizeof(check));
}

bool range(int x, int y) {
	return x >= 0 && x < n&& y >= 0 && y < n;
}

void bfs(int x, int y, char col) {
	check[x][y] = true;
	q.push({ x,y });

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (!range(nx, ny)) continue;

			if (check[nx][ny]) continue;

			if (arr[nx][ny] != col) continue;

			check[nx][ny] = true;
			q.push({ nx,ny });
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!check[i][j]) {
				char color = arr[i][j];
				bfs(i, j, color);
				cnt1++;
			}
		}
	}

	init();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 'G') arr[i][j] = 'R';
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!check[i][j]) {
				char color = arr[i][j];
				bfs(i, j, color);
				cnt2++;
			}
		}
	}
	cout << cnt1 << " " << cnt2;

	return 0;
}