#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int t;
int arr[55][55];
bool check[55][55]; //세로 가로
void init() {
	memset(check, false, sizeof(check));
	memset(arr, 0, sizeof(arr));
}

bool range(int x, int y, int n, int m) { // x 세로 y 가로
	return x >= 0 && x < n&& y >= 0 && y < m;
}

int bfs(int n, int m) {
	int cnt = 0;
	queue <pair<int, int>> q;	

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (check[i][j]) continue;

			if (arr[i][j] == 1) {
				q.push({ i,j });
				check[i][j] = true;
				cnt++;

				while (!q.empty()) {
					int cx = q.front().first;
					int cy = q.front().second;

					q.pop();

					for (int k = 0; k < 4; k++) {
						int nx = cx + dx[k];
						int ny = cy + dy[k];

						if (!check[nx][ny] && range(nx, ny, n, m) && arr[nx][ny] == 1) {
							check[nx][ny] = true;
							q.push({ nx,ny });
						}
					}
				}
			}
		}
	}

	return cnt;
}

int main() {
	cin >> t;
	while (t--) {
		init();
		int m, n, k;
		cin >> m >> n >> k;

		while (k--) {
			int x, y;
			cin >> x >> y;

			arr[y][x] = 1;
		}

		cout << bfs(n, m) << "\n";
	}

	return 0;
}