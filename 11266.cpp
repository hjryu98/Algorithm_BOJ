#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int v, e, idx;
int check[10005]; //dfs visiting order
bool cut[10005];
vector <int> graph[10005];

int dfs(int cur, bool root) {
	check[cur] = ++idx;
	int ret = check[cur];
	int cnt = 0; //자식의 개수

	for (int i = 0; i < graph[cur].size(); i++) {
		int nxt = graph[cur][i];

		if (check[nxt]) {
			ret = min(ret, check[nxt]);
			continue;
		}

		cnt++;
		int go = dfs(nxt, false);

		if (!root && go >= check[cur]) cut[cur] = true;

		ret = min(ret, go);
	}

	if (root) {
		cut[cur] = (cnt >= 2);
	}

	return ret;
}

int main() {
	cin >> v >> e;
	for (int i = 0; i < e; i++) {
		int a, b;
		cin >> a >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 1; i <= v; i++) {
		if (!check[i]) dfs(i, true);
	}

	int ans = 0;
	for (int i = 1; i <= v; i++) ans += cut[i];

	cout << ans << "\n";
	for (int i = 1; i <= v; i++) {
		if (cut[i]) cout << i << " ";
	}
	
	

	return 0;
}