#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int h, w, ex, ey;
char arr[505][505];
int d[505][505];

struct comp {
	bool operator()(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
		return a.second > b.second;
	}
};
priority_queue <pair<pair<int, int>, int>, vector <pair<pair<int, int>, int>>, comp> pq;

bool range(int x, int y) {
	return x >= 0 && x < h&& y >= 0 && y < w;
}

void dijkstra() {
	d[pq.top().first.first][pq.top().first.second] = 0;

	while (!pq.empty()) {
		int cx = pq.top().first.first;
		int cy = pq.top().first.second;
		int val = pq.top().second;

		pq.pop();

		int nx, ny;

		if (d[cx][cy] < val) continue;

		for (int i = 0; i < 4; i++) {
			nx = cx + dx[i];
			ny = cy + dy[i];

			if (!range(nx, ny)) continue;

			if (arr[nx][ny] == '#') continue;

			if (arr[cx][cy] == '1') {
				if (d[nx][ny] > val + 1) {
					d[nx][ny] = val + 1;
					pq.push({ {nx,ny}, d[nx][ny] });
				}
			}
			else {
				if (arr[nx][ny] == '1') {
					if (d[nx][ny] > val + 1) {
						d[nx][ny] = val + 1;
						pq.push({ {nx,ny}, d[nx][ny] });
					}
				}
				else {
					if (d[nx][ny] > val) {
						d[nx][ny] = val;
						pq.push({ {nx,ny}, d[nx][ny] });
					}
				}
			}

		}
	}
}


int main() {
	cin >> h >> w;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'S') {
				pq.push({ { i,j }, 0 });
				arr[i][j] = '.';
			}
			else if (arr[i][j] == 'E') {
				ex = i;
				ey = j;
				arr[i][j] = '.';
			}
		}
	}
	for (int i = 0; i < 505; i++) {
		for (int j = 0; j < 505; j++) d[i][j] = 999999999;
	}

	for (int i = 1; i < h - 1; i++) {
		for (int j = 1; j < w - 1; j++) {
			if (i >= 1 && i <= h - 2 && j >= 1 && j <= w - 2 && arr[i][j] == '#') {
				for (int k = 0; k < 4; k++) {
					if (arr[i + dx[k]][j + dy[k]] == '#') continue;
					arr[i + dx[k]][j + dy[k]] = '0';
				}
			}
			else if ((i >= 1 && i <= h - 2 && (j == 1 || j == w - 2))) arr[i][j] = '0';
			else if ((j >= 1 && j <= w - 2 && (i == 1 || i == h - 2))) arr[i][j] = '0';
			else {
				if (arr[i][j] == '.') arr[i][j] = '1';
			}
		}
	}

	dijkstra();
	cout << d[ex][ey] << "\n";

	return 0;
}