#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
vector <pair<int, int>> v[5003];
int n, q;
// 5000 * 10000 100000000
int bfs(int k, int val) {
	int cnt = 0;
	bool check[5003] = { 0, };
	queue <pair<int, int>> que;

	check[val] = true;
	que.push({ val, 999999999 });

	while (!que.empty()) {
		int cur = que.front().first;
		int ans = que.front().second;

		que.pop();

		for (int i = 0; i < v[cur].size(); i++) {
			int nxt = v[cur][i].first;
			int value = v[cur][i].second;

			if (check[nxt]) continue;

			ans = min(ans, value);

			if (ans >= k) {
				que.push({ nxt, ans });
				check[nxt] = true;
				cnt++;
			}

		}
	}
	return cnt;
	
}

bool comp(pair<int, int> a, pair<int, int> b) {
	if (a.second != b.second) return a.second > b.second;
	return a.first < b.first;
}


int main() {
	cin >> n >> q;
	for (int i = 0; i < n - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}

	for (int i = 1; i <= n; i++) sort(v[i].begin(), v[i].end(), comp);

	while (q--) {
		int a, b;
		cin >> a >> b;
		cout << bfs(a, b) << "\n";
	}

	return 0;
}