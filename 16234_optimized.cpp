#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
queue <pair<int, int>> q;
int n, l, r, cnt;
bool flag;
int arr[55][55];
int tmp[55][55];
bool check[55][55];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
bool range(int x, int y) {
	return x >= 0 && x < n&& y >= 0 && y < n;
}

void bfs(int x, int y) {
	vector <pair<int, int>> v;
	int sum = 0;

	sum += arr[x][y];
	v.push_back({ x,y });
	check[x][y] = true;
	q.push({ x,y });

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			int val = abs(arr[cx][cy] - arr[nx][ny]);
			if (range(nx, ny) && !check[nx][ny] && (l <= val && val <= r)) {
				q.push({ nx, ny });
				v.push_back({ nx,ny });
				check[nx][ny] = true;
				sum += arr[nx][ny];
			}
		}
	}

	int div = sum / v.size();
	for (int i = 0; i < v.size(); i++) {
		int nx = v[i].first;
		int ny = v[i].second;
		tmp[nx][ny] = div;
	}

}

void copying() {
	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == tmp[i][j]) {
				count++;
				continue;
			}
			arr[i][j] = tmp[i][j];
		}
	}

	if (count == n * n) flag = true;
}

int main() {
	fastio;
	cin >> n >> l >> r;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cin >> arr[i][j];
	}

	while (1) {
		memset(check, 0, sizeof(check));
		memset(tmp, 0, sizeof(tmp));
		while (!q.empty()) q.pop();

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!check[i][j]) {
					bfs(i, j);
				}
			}
		}
		copying();
		if (flag) break;
		cnt++;
	}
	cout << cnt;

	return 0;
}