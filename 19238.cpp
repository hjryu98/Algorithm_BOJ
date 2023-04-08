#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <map>
using namespace std;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int n, m, tx, ty, gonum, cnt;
int fuel;
int arr[25][25]; //first 승객, second 도착지
bool check[25][25]; 
bool broke; //갈수가 없음
/*
출발지는 달라도, 도착지가 겹칠 수 있음! >> map으로 처리해주었다. 
*/
struct customer {
	int ex;
	int ey;
};

map <int, customer> mm;

bool range(int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= n;
}

void dept() {
	int dist = 0;
	queue <pair<int, int>> q;
	memset(check, 0, sizeof(check));

	check[tx][ty] = true;
	q.push({ tx,ty });

	int gx = 0, gy = 0; //이 승객을 태울 것임

	while (!q.empty()) {
		int size = q.size();

		while (size--) {
			int cx = q.front().first;
			int cy = q.front().second;

			q.pop();

			if (arr[cx][cy] >= 1 && arr[cx][cy] <= m) {
				if (gx == 0 && gy == 0) {
					gx = cx;
					gy = cy;
				}
				else {
					if (cx < gx) {
						gx = cx;
						gy = cy;
					}
					else if (cx == gx) {
						if (cy < gy) {
							gx = cx;
							gy = cy;
						}
					}
				}
			}

			for (int i = 0; i < 4; i++) {
				int nx = cx + dx[i];
				int ny = cy + dy[i];

				if (!range(nx, ny)) continue;

				if (check[nx][ny]) continue;

				if (arr[nx][ny] == 999) continue;

				check[nx][ny] = true;
				q.push({ nx,ny });
			}
		}

		if (gx != 0 && gy != 0) {
			break;
		}

		dist++;
	}

	if (gx == 0 && gy == 0 && cnt != m) {
		broke = true;
		return;
	}

	fuel -= dist;

	if (fuel <= 0) {
		broke = true;
		return;
	}

	tx = gx;
	ty = gy;
	gonum = arr[tx][ty];
	arr[tx][ty] = 0;
}

void arrive() {
	int dist = 0;
	queue <pair<int, int>> q;
	memset(check, 0, sizeof(check));
	bool flag = false;
	check[tx][ty] = true;
	q.push({ tx,ty });

	int gx = 0, gy = 0; //이 승객을 태울 것임

	while (!q.empty()) {
		int size = q.size();

		while (size--) {
			int cx = q.front().first;
			int cy = q.front().second;

			q.pop();

			if (mm[gonum].ex == cx && mm[gonum].ey == cy) {
				gx = cx;
				gy = cy;
				flag = true;
				break;
			}

			for (int i = 0; i < 4; i++) {
				int nx = cx + dx[i];
				int ny = cy + dy[i];

				if (!range(nx, ny)) continue;

				if (check[nx][ny]) continue;

				if (arr[nx][ny] == 999) continue;

				check[nx][ny] = true;
				q.push({ nx,ny });
			}
		}

		if (flag) break;
		dist++;
	}

	if (!flag && cnt != m) {
		broke = true;
		return;
	}

	fuel -= dist;
	mm[gonum] = { 0 ,0 };

	if (fuel < 0) {
		broke = true;
		return;
	}


	fuel += dist * 2;
	tx = gx;
	ty = gy;
	gonum = 0;
	cnt++;
}

void solve() {
	while (1) {
		if (cnt == m) {
			cout << fuel;
			return;
		}

		dept();
		if (broke) {
			cout << -1;
			return;
		}

		arrive();
		if (broke) {
			cout << -1;
			return;
		}
	}
}


int main() {
	cin >> n >> m >> fuel;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) arr[i][j] = 999;
		}
	}
	cin >> tx >> ty;

	int cur = 1;
	for (int i = 1; i <= m; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		arr[a][b] = cur;
		mm[cur++] = { c,d };
	}
	solve();

	return 0;
}