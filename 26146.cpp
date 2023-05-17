#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <iostream>
#include <stack>
#include <vector>
#include <cstring>
using namespace std;
int n, m, cnt;
vector <int> v[200002];
vector <int> rv[200002];
bool check[200002];
stack <int> st;
void dfs(int cur) {
	check[cur] = true;

	for (int i = 0; i < v[cur].size(); i++) {
		if (!check[v[cur][i]]) dfs(v[cur][i]);
	}
	st.push(cur);
}

void rdfs(int cur) {
	check[cur] = true;
	
	for (int i = 0; i < rv[cur].size(); i++) {
		if (!check[rv[cur][i]]) rdfs(rv[cur][i]);
	}
}

int main() {
	fastio;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		rv[b].push_back(a);
	}
	
	for (int i = 1; i <= n; i++) {
		if (!check[i]) dfs(i);
	}

	memset(check, false, sizeof(check));
	while (!st.empty()) {
		int val = st.top();
		st.pop();

		if (check[val]) continue;
		rdfs(val);
		cnt++;
	}
	cout << ((cnt == 1) ? "Yes\n" : "No\n");

	return 0;
}