#define INF 999999999
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
int t;

void dijkstra(vector <pair<pair<int, int>, int>> vec[120], int dist[120][10002], int m) {
	priority_queue <pair<pair<int, int>,int>> pq;
	pq.push({ {0, 1},0 });
	dist[1][0] = 0; 
	
	while (!pq.empty()) {
		int cur = pq.top().first.second; //현재 노드, 가는데 든 거리, 가는데 든 비용
		int curdist = -1 * pq.top().first.first;
		int curcost = pq.top().second;

		pq.pop();

		if (dist[cur][curcost] < curdist) continue;

		for (int i = 0; i < vec[cur].size(); i++) {
			int nxt = vec[cur][i].second;
			int nxtcost = vec[cur][i].first.first;
			int nxtdist = vec[cur][i].first.second;

			if (curcost + nxtcost > m) continue;

			if (dist[nxt][curcost + nxtcost] > curdist + nxtdist) {
				dist[nxt][curcost + nxtcost] = curdist + nxtdist;
				pq.push({ { -1 * dist[nxt][curcost + nxtcost], nxt }, curcost + nxtcost });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while (t--) {
		vector <pair<pair<int, int>, int>> vec[120];
		int n, m, k;
		int dist[120][10002] = { 0, };//i번째 노드를 가는데 드는 비용 j를 써서 간 시간 >> 무한대 초기화 필요
		cin >> n >> m >> k;

		for (int i = 0; i < 120; i++) {
			for (int j = 0; j < 10002; j++) dist[i][j] = INF;
		}

		for (int i = 0; i < k; i++) {
			int v, u, c, d;
			cin >> v >> u >> c >> d;

			if (c > m) continue; //절대 못지나가는 간선
			vec[v].push_back({ {c,d}, u });
		}
		dijkstra(vec, dist, m);

		int ans = 999999999;

		for (int i = 0; i <= m; i++) {
			ans = min(ans, dist[n][i]);
		}
		if (ans == INF) cout << "Poor KCM\n";
		else cout << ans << "\n";
	}
	return 0;
}