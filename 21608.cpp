#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int n, ans;
int arr[22][22];
bool prefer[410][410];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int score[] = { 0,1,10,100,1000 };
queue <int> q;

bool comp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
	if (a.first != b.first) return a.first > b.first;
	else {
		if (a.second.first != b.second.first) return a.second.first < b.second.first;
		return a.second.second < b.second.second;
	}
}

bool range(int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= n;
}

void solve() {
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		vector < pair<int, pair<int, int>>> v;
		int lvl = 0; 

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				int count = 0;
				int zero = 0;
				int cx = i;
				int cy = j;
				if (arr[cx][cy]) continue;

				for (int k = 0; k < 4; k++) {
					int nx = cx + dx[k];
					int ny = cy + dy[k];
					if (!range(nx, ny)) continue;

					if (prefer[cur][arr[nx][ny]]) count++;

					if (!arr[nx][ny]) zero++;
				}

				if (lvl < count) {
					while (!v.empty()) v.pop_back();
					lvl = count;
					v.push_back({ zero,{cx, cy} });
				}

				else if (lvl == count) v.push_back({ zero,{cx,cy} });
			}
		}
		sort(v.begin(), v.end(), comp);

		int x = v[0].second.first;
		int y = v[0].second.second;
		arr[x][y] = cur;
	}
}

void calc() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int cx = i;
			int cy = j;

			int cnt = 0;

			for (int k = 0; k < 4; k++) {
				int nx = cx + dx[k];
				int ny = cy + dy[k];

				if (!range(nx, ny)) continue;

				if (prefer[arr[cx][cy]][arr[nx][ny]]) cnt++;
			}
			ans += score[cnt];
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n * n; i++) {
		int a, b, c, d, e;
		cin >> a >> b >> c >> d >> e;
		q.push(a);
		prefer[a][b] = prefer[a][c] = prefer[a][d] = prefer[a][e] = true;
	}

	solve();

	calc();

	cout << ans;

	return 0;
}