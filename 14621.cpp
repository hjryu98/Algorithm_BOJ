#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
int ans;
int par[1005];
char arr[1005];
vector <pair<int, pair<int, int>>> v;

int find(int x) {
	if (x == par[x]) return x;
	return par[x] = find(par[x]);
}

void merge(int a, int b) {
	int para = find(a);
	int parb = find(b);

	if (para > parb) par[para] = parb;
	else par[parb] = para;
}

int main() {
	fastio;
	cin >> n >> m;

	for (int i = 0; i < n; i++) cin >> arr[i];

	for (int i = 0; i <= n; i++) par[i] = i;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		v.push_back({ c,{a,b} });
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < m; i++) {
		if (arr[v[i].second.first] == arr[v[i].second.second]) continue;

		if (find(v[i].second.first) != find(v[i].second.second)) {
			merge(v[i].second.first, v[i].second.second);
			ans += v[i].first;
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (find(i) == 1) cnt++;
	}
	if (cnt == n) cout << ans;
	else cout << -1;


	return 0;
}