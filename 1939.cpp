#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int n, m, s, e;
int par[10005];
bool check[10005];
vector <pair<int, pair<int, int >>> edge;
vector <pair<int, int>> v[10005];
void init() {
	for (int i = 0; i < 10005; i++) par[i] = i;
}

int find(int x) {
	if (par[x] == x) return x;
	return par[x] = find(par[x]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);

	if (a > b) par[a] = b;
	else par[b] = a;
}

bool comp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
	return a.first > b.first;
}

bool intcheck(int value) {
	queue <int> q;
	memset(check, false, sizeof(check));
	check[s] = true;
	q.push(s);

	while (!q.empty()) {
		int cur = q.front();

		q.pop();

		if (cur == e) return true;

		for (int i = 0; i < v[cur].size(); i++) {
			int nx = v[cur][i].first;
			int val = v[cur][i].second;

			if (!check[nx]) {
				if (val < value) continue;
				check[nx] = true;
				q.push(nx);
			}
		}
	}
	return false;
}

int main() {
	init();
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edge.push_back({ c, {a,b} });
	}
	cin >> s >> e;
	sort(edge.begin(), edge.end(), comp);
	for (int i = 0; i < edge.size(); i++) {
		int a = edge[i].second.first;
		int b = edge[i].second.second;
		int c = edge[i].first;
		if (find(a) != find(b)) {
			merge(a, b);
			v[a].push_back({ b,c });
			v[b].push_back({ a,c });
		}
	}

	int start = 1;
	int end = 1000000001;

	while (start + 1 < end) {
		int mid = (start + end) / 2;

		if (intcheck(mid)) start = mid;
		else end = mid;
	}

	cout << start;

	return 0;
}