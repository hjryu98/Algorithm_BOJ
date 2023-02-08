#include <iostream>
using namespace std;
int n, m;
int dir[8][2] = { {0,1},{0,-1},{-1,0},{1,0},{1, -1},{1, 1},{-1,1},{-1,-1} };
int arr[105][75];
bool check[105][75];
bool flag;
int ans;

bool range(int x, int y) {
	return x >= 0 && x < n&& y >= 0 && y < m;
}

void dfs(int x, int y) {
	check[x][y] = true;

	for (int i = 0; i < 8; i++) {
		int nx = x + dir[i][0];
		int ny = y + dir[i][1];

		if (range(nx, ny)) {
			if (arr[nx][ny] > arr[x][y]) flag = false;

			if (arr[nx][ny] == arr[x][y] && !check[nx][ny]) dfs(nx, ny);
		}
	}
}


int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cin >> arr[i][j];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			flag = true;
			if (!check[i][j] && arr[i][j] > 0) {
				dfs(i, j);
				if (flag) ans++;
			}
		}
	}
	cout << ans;

	return 0;
}