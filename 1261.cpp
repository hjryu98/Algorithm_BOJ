#include <iostream>
#include <queue>
using namespace std;

struct comp {
	bool operator()(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
		return a.second > b.second;
	}
};
int n, m;
int d[105][105];
char arr[105][105];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
priority_queue <pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, comp > pq;

bool range(int x, int y) {
	return x >= 0 && x < n&& y >= 0 && y < m;
}

void dijkstra(int x, int y) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) d[i][j] = 999999999;
	}

	d[x][y] = 0;
	pq.push({ {x,y}, 0 });

	while (!pq.empty()) {
		int cx = pq.top().first.first;
		int cy = pq.top().first.second;
		int val = pq.top().second;

		pq.pop();

		if (d[cx][cy] < val) continue;

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (!range(nx, ny)) continue;

			if (d[nx][ny] > val + (arr[nx][ny] - '0')) {
				d[nx][ny] = val + (arr[nx][ny] - '0');
				pq.push({ {nx,ny}, d[nx][ny] });
			}
		}
	}
}

int main() {
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	dijkstra(0, 0);

	cout << d[n - 1][m - 1];

	return 0;
}