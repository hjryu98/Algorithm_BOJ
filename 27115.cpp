#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n, m, k, ans;
int arr[3002][3002];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
vector <pair<int, pair<int, int>>> v;
queue <pair<int, int>> q;

bool range(int x, int y) {
	return x >= 1 && x <= n&& y >= 1 && y <= m;
}

int main() {
	cin >> n >> m >> k;
	while (k--) {
		int a, b, c;
		cin >> a >> b >> c;

		v.push_back({ c,{a,b} });
	}
	sort(v.begin(), v.end());

	for (int w = 3000; w >= 1; w--) {
		while (!v.empty() && v.back().first == w) {
			if (!arr[v.back().second.first][v.back().second.second]) {
				arr[v.back().second.first][v.back().second.second] = 1;
				q.push(v.back().second);
			}
			v.pop_back();
		}
		int size = q.size();
		while (size--) {
			int cx = q.front().first;
			int cy = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = cx + dx[i];
				int ny = cy + dy[i];

				if (range(nx, ny) && !arr[nx][ny]) {
					arr[nx][ny] = 1;
					q.push({ nx,ny });
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) ans += arr[i][j];
	}
	cout << ans;

	return 0;
}