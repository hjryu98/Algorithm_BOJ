#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, cnt;
int q[200002];
vector <int> v[200002];
vector <bool> ans(200002);
bool check[200002];
int par[200002];

void init() {
	for (int i = 0; i < 200002; i++) par[i] = i;
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
			if (check[nxt]) {
				if (find(nxt) != find(cur)) {
					merge(nxt, cur);
					cnt--;
				}
			}
		}
		check[cur] = true;
		ans.push_back(cnt == 1);
	}
	reverse(ans.begin(), ans.end());

	for (int i = 0; i <= n; i++) cout << (ans[i] == true ? "CONNECT\n" : "DISCONNECT\n");
	
	return 0;
}