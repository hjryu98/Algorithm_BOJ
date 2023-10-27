#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int n, m;
bool check[1003];
int dist[1003];
vector <pair<int, int>> v[1003];
bool flag;

void init() {
	memset(check, false, sizeof(check));
	memset(dist, 0, sizeof(dist));
	flag = false;
}

void dfs(int cur, int prv, int goto1) {
	if (flag) return;
	
	check[cur] = true;

	dist[cur] = prv;

	if (cur == goto1) {
		flag = true;
		return;
	}

	for (int i = 0; i < v[cur].size(); i++) {
		int nxt = v[cur][i].first;
		int val = v[cur][i].second;

		if (check[nxt]) continue;

		dfs(nxt, prv + val, goto1);
	}

}

int main() {
	cin >> n >> m;
	
	for (int i = 0; i < n - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	while (m--) {
		init();
		int a, b;
		cin >> a >> b;
		dfs(a, 0, b);
		cout << dist[b] << "\n";
	}

	return 0;
}