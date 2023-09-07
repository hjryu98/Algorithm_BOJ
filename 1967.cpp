#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int n, str, maxw;
vector <pair<int,int>> v[10003];
bool check[10003];

void init() {
	memset(check, false, sizeof(check));
	maxw = 0;
}

void dfs(int cur, int score) {
	check[cur] = true;
	
	for (int i = 0; i < v[cur].size(); i++) {
		int nxt = v[cur][i].first;
		int w = v[cur][i].second;

		if (!check[nxt]) {
			if (w + score > maxw) {
				maxw = w + score;
				str = nxt;
			}
			dfs(nxt, w + score);
		}
	}
}

void dfs2(int cur, int score) {
	check[cur] = true;

	for (int i = 0; i < v[cur].size(); i++) {
		int nxt = v[cur][i].first;
		int w = v[cur][i].second;

		if (!check[nxt]) {
			if (w + score > maxw) {
				maxw = w + score;
			}
			dfs(nxt, w + score);
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	dfs(1, 0);
	init();
	dfs2(str, 0);
	cout << maxw;

	return 0;
}