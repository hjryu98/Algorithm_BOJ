#include <iostream>
using namespace std;
int n, m, r, c, d;
int arr[55][55];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
bool range(int x, int y) {
	return x >= 0 && x < n&& y >= 0 && y < m;
}

void solve() {
	while (1) {
		bool togoclean = false;
		if (arr[r][c] == 0) {
			arr[r][c] = 2;
		}

		for (int i = 0; i < 4; i++) {
			int nx = r + dx[i];
			int ny = c + dy[i];
			if (!range(nx, ny)) continue;

			if (arr[nx][ny] == 0) {
				togoclean = true;
				break;
			}
		}
		if (togoclean) {
			d = (d + 3) % 4;
			int nx = r + dx[d];
			int ny = c + dy[d];
			if (range(nx, ny) && arr[nx][ny] == 0) {
				r = nx;
				c = ny;
			}
		}
		else {
			int nx = r - dx[d];
			int ny = c - dy[d];
			if (range(nx, ny) && arr[nx][ny] != 1) {
				r = nx;
				c = ny;
			}
			else break;
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 2) cnt++;
		}
	}
	cout << cnt;
}

int main() {
	cin >> n >> m >> r >> c >> d;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cin >> arr[i][j];
	}

	solve();
	return 0;
}