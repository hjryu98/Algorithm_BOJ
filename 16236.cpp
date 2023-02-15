#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
int n, ans;
int curx, cury, cureat, fishsize = 2;
int arr[23][23];
bool check[23][23];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

bool range(int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= n;
}

void bfs(int x, int y) {
	queue <pair<int, int>> q;
	check[x][y] = true;
	q.push({ x,y });
	int tmp = 0;

	while (!q.empty()) {
		int size = q.size();
		int ex = 0, ey = 0;

		while (size--) {
			int cx = q.front().first;
			int cy = q.front().second;

			q.pop();

			if (arr[cx][cy] > 0 && arr[cx][cy] < fishsize) {
				if (ex == 0 && ey == 0) {
					ex = cx;
					ey = cy;
				}
				else {
					if (cx < ex) {
						ex = cx;
						ey = cy;
					}
					else if (cx == ex && cy < ey) {
						ex = cx;
						ey = cy;
					}
				}
			}

			if (size == 0 && (ex != 0 && ey != 0)) {
				arr[ex][ey] = 0;
				cureat++;

				if (cureat == fishsize) {
					cureat = 0;
					fishsize++;
				}

				ans += tmp;
				tmp = 0;
				memset(check, 0, sizeof(check));
				check[ex][ey] = true;
				while (!q.empty()) q.pop();
				cx = ex;
				cy = ey;
			}

			for (int i = 0; i < 4; i++) {
				int nx = cx + dx[i];
				int ny = cy + dy[i];

				if (range(nx, ny) && !check[nx][ny] && arr[nx][ny] <= fishsize) {
					check[nx][ny] = true;
					q.push({ nx,ny });
				}
			}
		}
		tmp++;
	}

}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 9) {
				curx = i;
				cury = j;
				arr[i][j] = 0;
			}
		}
	}

	bfs(curx, cury);
	cout << ans;

	return 0;
}