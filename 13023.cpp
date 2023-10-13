#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int n, m;
vector <int> v[2005];
bool check[2005];
bool flag;
void init() {
	memset(check, false, sizeof(check));
}

void dfs(int cur, int dep) {
	check[cur] = true;

	if (flag) return;

	if (dep >= 5) {
		flag = true;
		return;
	}

	for (int i = 0; i < v[cur].size(); i++) {
		int nx = v[cur][i];
		if (!check[nx]) {
			dfs(nx, dep + 1);
			check[nx] = false;
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 0; i < n; i++) {
		dfs(i, 1);
		// cout << i << "\n";
		if (flag) break;
		init();
	}
	cout << ((flag) ? 1 : 0);

	return 0;
}