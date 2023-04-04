#define inf 999999999
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int n, m, ans = inf, rem;
int arr[55][55];
bool check[55][55];
int slt[15];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
vector <pair<int, int>> virus;

bool range(int x, int y) {
	return x >= 0 && x < n&& y >= 0 && y < n;
}

int checking() {
	queue <pair<int, int>> q;
	memset(check, false, sizeof(check));
	int sum = 0;
	int tmp = rem;

	for (int i = 0; i < m; i++) {
		int x = virus[slt[i]].first;
		int y = virus[slt[i]].second;

		q.push({ x,y });
		check[x][y] = true;
	}

	if (tmp == 0) return 0;

	while (!q.empty()) {
		int size = q.size();

		while (size--) {
			int cx = q.front().first;
			int cy = q.front().second;

			q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = cx + dx[i];
				int ny = cy + dy[i];

				if (!range(nx, ny)) continue;

				if (!check[nx][ny] && arr[nx][ny] != 1) {
					if (arr[nx][ny] == 0) {
						tmp--;
						if (tmp == 0) return sum + 1;
					}
					q.push({ nx,ny });
					check[nx][ny] = true;
				}
			}
		}
		sum++;
	}
	return inf;
}

void recur(int cnt, int prv) {
	if (cnt >= m) {
		ans = min(ans, checking());
		return;
	}

	for (int i = prv; i < virus.size(); i++) {
		slt[cnt] = i;
		recur(cnt + 1, i + 1);
		slt[cnt] = 0;
	}
}


int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) virus.push_back({ i,j });

			else if (arr[i][j] == 0) rem++;
		}
	}
	
	recur(0, 0);
	if (ans == inf) cout << -1;
	else cout << ans;

	return 0;
}