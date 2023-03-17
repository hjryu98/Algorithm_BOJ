#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, ans;
int arr[55][55];
bool check[55][55]; //전단계에 구름이 있었는가?
int dx[] = { 0,-1,-1,-1,0,1,1,1 };
int dy[] = { -1,-1,0,1,1,1,0,-1 };
vector <pair<int, int>> cloud;

bool range(int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= n;
}

void update() { 
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (check[i][j]) continue;

			if (arr[i][j] >= 2) {
				arr[i][j] -= 2;
				cloud.push_back({ i,j });
			}
		}
	}
}

void magic(vector <pair<int, int>> tmp) { //물복사 버그
	int size = tmp.size();

	for (int i = 0; i < size; i++) {
		int cx = tmp[i].first;
		int cy = tmp[i].second;
		int cnt = 0;
		for (int j = 1; j <= 7; j += 2) {
			int nx = cx + dx[j];
			int ny = cy + dy[j];
			if (!range(nx, ny)) continue;
			if (arr[nx][ny] > 0) cnt++;
		}
		arr[cx][cy] += cnt;
	}
}

void moving(int dist, int d, int cur) {
	vector < pair<int, int>> tmp;
	memset(check, false, sizeof(check));

	if (cur == 1) {
		cloud.push_back({ n,1 });
		cloud.push_back({ n,2 });
		cloud.push_back({ n - 1,1 });
		cloud.push_back({ n - 1,2 });
	}

	int size = cloud.size();

	for (int i = size - 1; i >= 0; i--) {
		int cx = cloud[i].first;
		int cy = cloud[i].second;
		cloud.pop_back();

		cx += dist * dx[d];
		cy += dist * dy[d];

		if (!range(cx, cy)) {
			if (cx <= 0) while (cx <= 0) cx += n;
			if (cx > n) while (cx > n) cx -= n;
			if (cy <= 0) while (cy <= 0) cy += n;
			if (cy > n) while (cy > n) cy -= n;
		}

		arr[cx][cy]++;
		check[cx][cy] = true;
		tmp.push_back({ cx,cy }); ///이번에 물이 증가한 곳을 저장해둠
	}
	magic(tmp);
	update();
}

void query(int d, int s, int cur) {
	int dist = s % n;
	moving(dist, d, cur);
}

void solve() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) ans += arr[i][j];
	}
	cout << ans;
}

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) cin >> arr[i][j];
	}

	for (int i = 1; i <= m; i++) {
		int dir, speed;
		cin >> dir >> speed;
		query(dir - 1, speed, i);
	}

	solve();

	return 0;
}