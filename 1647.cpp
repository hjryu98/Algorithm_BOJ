#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <pair<int, pair<int, int>>> edge; //모든 간선들을 저장해둔 벡터
int n, m;
int ans, cur;
int par[100002];

int find(int x) {
	if (x == par[x]) return x;
	return par[x] = find(par[x]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);

	par[a] = b;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edge.push_back({ c,{a,b} });
	}

	for (int i = 0; i < 100002; i++) par[i] = i;

	sort(edge.begin(), edge.end());

	for (int i = 0; i < edge.size(); i++) {
		int a = edge[i].second.first;
		int b = edge[i].second.second;
		int c = edge[i].first;
		if (find(a) != find(b)) {
			merge(a, b);
			cur = max(cur, c);
			ans += c;
		}
	}
	cout << ans - cur;

	return 0;
}