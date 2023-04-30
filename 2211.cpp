#define inf 999999999
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n, m, dist[1005];
vector <pair<int, int>> v[1005];
int least[1005];
struct node {
	int num, val;
};

struct comp {
	bool operator()(node a, node b) {
		return a.val > b.val;
	}
};

priority_queue <node, vector<node>, comp> pq;

void dijkstra(int start) {
	dist[start] = 0;
	pq.push({ start, 0 });

	while (!pq.empty()) {
		int cur = pq.top().num;
		int val = pq.top().val;

		pq.pop();

		if (val > dist[cur]) continue;

		for (int i = 0; i < v[cur].size(); i++) {
			int nxt = v[cur][i].first;
			int cost = v[cur][i].second;

			if (dist[nxt] > cost + val) {
				dist[nxt] = cost + val;
				pq.push({ nxt, dist[nxt] });
				least[nxt] = cur;
			}	
		}
	}
}

void init() {
	for (int i = 0; i < 1005; i++) {
		dist[i] = inf;
		least[i] = 0;
	}
}

int main() {
	cin >> n >> m;
	init();
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	dijkstra(1);
	int cnt = 0;
	for (int i = 2; i <= n; i++) {
		if (least[i]) cnt++;
	}
	cout << cnt << "\n";
	for (int i = 2; i <= n; i++) {
		if (least[i]) cout << i << " " << least[i] << "\n";
	}

	return 0;
}