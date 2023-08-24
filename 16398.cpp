#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
int n;
int par[1005]; // par[i] : i 의 부모가~
vector <pair<pair<int, int>, int>> edge;
ll ans;

bool comp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
	return a.second < b.second;
}

int find(int x) {
	if (x == par[x]) return x;
	return par[x] = find(par[x]);
}

void union_(int a, int b) {
	a = find(a);
	b = find(b);

	if (a > b) par[a] = b;
	else par[b] = a;
}


int main() {
	cin >> n;

	for (int i = 0; i < 1005; i++) par[i] = i;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int a;
			cin >> a;
			if (j <= i) continue;
			
			edge.push_back({ {i, j} , a });
		}
	}
	sort(edge.begin(), edge.end(), comp);

	for (int i = 0; i < edge.size(); i++) {
		int u = edge[i].first.first;
		int v = edge[i].first.second;
		int w = edge[i].second;

		if (find(u) != find(v)) {
			union_(u, v);
			ans += w;
		}
	}
	cout << ans;
	

	return 0;
}