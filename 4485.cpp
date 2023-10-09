#define inf 999999999
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
int arr[130][130];
int dist[130][130];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int n;

struct info {
	int x; int y; int val;
};

struct comp {
	bool operator()(info a, info b) {
		return a.val > b.val;
	}
};

priority_queue<info, vector<info>, comp> pq;

void init() {
	memset(arr, 0, sizeof(arr));
	for (int i = 0; i < 130; i++) {
		for (int j = 0; j < 130; j++) dist[i][j] = inf;
	}
	while (!pq.empty()) pq.pop();
}

bool range(int x, int y) {
	return x >= 0 && x < n&& y >= 0 && y < n;
}

void dijkstra() {
	while (!pq.empty()) {
		int x = pq.top().x;
		int y = pq.top().y;
		int val = pq.top().val;

		pq.pop();

		if (dist[x][y] < val) continue;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (!range(nx, ny)) continue;

			if (dist[nx][ny] > dist[x][y] + arr[nx][ny]) {
				dist[nx][ny] = dist[x][y] + arr[nx][ny];
				pq.push({ nx,ny, dist[nx][ny] });
			}
		}
	}
}

int main() {
	int idx = 1;
	while (cin >> n) {
		if (!n) break;
		init();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) cin >> arr[i][j];
		}

		dist[0][0] = arr[0][0];
		pq.push({ 0,0,dist[0][0] });
		dijkstra();
		cout << "Problem " << idx++ << ": " << dist[n - 1][n - 1] << "\n";
	}

	return 0;
}