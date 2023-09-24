#define inf 999999999
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
int n, m;
int dist[50002];
vector <pair<int, int>> vec[50002];

struct info {
	int cur;
	int val;
};

struct comp {
	bool operator()(info a, info b) {
		if (a.val != b.val) return a.val > b.val;
		return a.cur > b.cur;
	}
};
priority_queue <info, vector<info>, comp> pq;

void init() {
	for (int i = 0; i < 50002; i++) dist[i] = inf;
}

void dijkstra() {
	dist[1] = 0;
	pq.push({ 1, 0 });

	while (!pq.empty()) {
		int cur = pq.top().cur;
		int val = pq.top().val;

		pq.pop();

		if (val > dist[cur]) continue;

		for (int i = 0; i < vec[cur].size(); i++) {
			int nxt = vec[cur][i].first;
			int cost = vec[cur][i].second;

			if (dist[nxt] > dist[cur] + cost) {
				dist[nxt] = dist[cur] + cost;
				pq.push({ nxt, dist[nxt] });
			}
		}
	}
}

int main() {
	init();
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		vec[a].push_back({b,c});
		vec[b].push_back({a,c});
	}

	dijkstra();
	cout << dist[n];

	return 0;
}