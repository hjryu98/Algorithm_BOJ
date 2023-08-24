#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <iostream>
#include <vector>
using namespace std;
int dp[100005];
vector <int> v[100005];
bool check[100005];
int n, r, q;

int dfs(int cur) {
	int cnt = 1;
	check[cur] = true;

	for (int i = 0; i < v[cur].size(); i++) {
		if (check[v[cur][i]]) continue;

		cnt += dfs(v[cur][i]);
	}
	
	return dp[cur] = cnt;
}

int main() {
	fastio;
	cin >> n >> r >> q;

	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	dfs(r);

	while (q--) {
		int a;
		cin >> a;
		cout << dp[a] << "\n";
	}

	return 0;
}