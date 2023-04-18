#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, cnt;
bool present[200003];
int par[200003];
int q[200003];
vector <int> v[200003];
vector <bool> ans;

void init() {
	for (int i = 0; i < 200003; i++) par[i] = i;
}

int find(int x) {
	if (x == par[x]) return x;
	return par[x] = find(par[x]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);

	if (a > b) par[a] = b;
	else par[b] = a;
}

int main() {
	fastio;
	cin >> n >> m;

	init();

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 0; i < n; i++) cin >> q[i];

	for (int i = n - 1; i >= 0; i--) {
		int cur = q[i];
		cnt++;

		for (int j = 0; j < v[cur].size(); j++) {
			int nxt = v[cur][j];

			if (present[nxt]) {
				if (find(cur) != find(nxt)) {
					merge(cur, nxt);
					cnt--;
				}
			}
		}
		present[cur] = true;
		ans.push_back(cnt == 1);
	}
	reverse(ans.begin(), ans.end());

	for (int i = 0; i < ans.size(); i++) cout << ((ans[i] == 1) ? "YES\n" : "NO\n");

	return 0;
}