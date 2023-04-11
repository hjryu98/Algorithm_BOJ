#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n, m, k, x;
vector <int> v[300002];
vector <int> ans;
bool check[300002];
queue <int> q;
void bfs(int a) {
	check[a] = true;
	q.push(a);
	int dist = 0;
	while (!q.empty()) {
		int size = q.size();

		while (size--) {
			int cur = q.front();

			q.pop();

			if (dist >= k) return;

			for (int i = 0; i < v[cur].size(); i++) {
				int nx = v[cur][i];

				if (!check[nx]) {
					if (dist == k - 1) ans.push_back(nx);
					q.push(nx);
					check[nx] = true;
				}
			}
		}
		dist++;
	}
}
int main() {
	fastio;
	cin >> n >> m >> k >> x;
	while (m--) {
		int a, b;
		cin >> a >> b;

		v[a].push_back(b);
	}
	bfs(x);
	sort(ans.begin(), ans.end());
	if (ans.empty()) cout << -1;
	else {
		for (int i = 0; i < ans.size(); i++) cout << ans[i] << "\n";
	}

	return 0;
}