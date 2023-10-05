#include <iostream>
#include <algorithm>
using namespace std;
int n, m, arr[503][503], ans;
bool check[503][503];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

bool range(int x, int y) {
	return x >= 0 && x < n&& y >= 0 && y < m;
}

void recur(int cnt, int sum, int x, int y) {
	if (cnt >= 4) {
		ans = max(ans, sum);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (!range(nx, ny) || check[nx][ny]) continue;

		check[nx][ny] = true;
		recur(cnt + 1, sum + arr[nx][ny], nx, ny);
		if (cnt == 2) recur(cnt + 1, sum + arr[nx][ny], x, y);
		check[nx][ny] = false;
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			check[i][j] = true;
			recur(1, arr[i][j], i, j);
			check[i][j] = false;
		}
	}
	cout << ans;

	return 0;
}