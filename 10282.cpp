#define inf 999999999
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int t, cnt, ans;
int dist[10005];
vector <pair<int, int>> v[10005];

struct comp {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		return a.second > b.second;
	}
};

void init() {
	for (int i = 0; i < 10005; i++) {
		dist[i] = inf;
		v[i].clear();
	}
	cnt = ans = 0;
}

void calc(int n) {
	for (int i = 1; i <= n; i++) {
		if (dist[i] != inf) {
			cnt++;
			ans = max(ans, dist[i]);
		}
	}
}

void dijkstra(int c) {
	priority_queue <pair<int, int>, vector<pair<int, int>>, comp> pq;
	dist[c] = 0;
	pq.push({ c, 0 });
	while (!pq.empty()) {
		int cur = pq.top().first;
		int val = pq.top().second;
		pq.pop();

		for (int i = 0; i < v[cur].size(); i++) {
			int nx = v[cur][i].first;
			int cost = v[cur][i].second;

			if (dist[nx] > cost + dist[cur]) {
				dist[nx] = cost + dist[cur];

				pq.push({ nx, dist[nx] });
			}
		}
	}
}

int main() {
	cin >> t;
	while (t--) {
		init();
		int n, d, c;
		cin >> n >> d >> c;

		for (int i = 0; i < d; i++) {
			int a, b, s;
			cin >> a >> b >> s;
			v[b].push_back({ a,s });
		}
		dijkstra(c);
		calc(n);
		cout << cnt << " " << ans << "\n";
	}

	return 0;
}