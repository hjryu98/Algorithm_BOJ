#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <iostream>
#include <algorithm>
using namespace std;
int n, m, k;
int par[10005]; //최종 상위 부모는 0이라고 잡자.
pair<int, int> arr[10005];
int ans;

int find(int x) {
	if (x == par[x]) return x;
	return par[x] = find(par[x]);
}

void merge(int a, int b) {
	int ax = find(a);
	int bx = find(b);

	if (ax > bx) par[ax] = bx;
	else par[bx] = ax;
}

int main() {
	fastio;
	cin >> n >> m >> k;

	for (int i = 0; i <= n; i++) par[i] = i;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i].first;
		arr[i].second = i;
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		if (find(a) != find(b)) merge(a, b);
	}

	sort(arr + 1, arr + 1 + n);

	for (int i = 1; i <= n; i++) {
		if (find(arr[i].second) != find(0)) {
			if (ans + arr[i].first > k) continue;
			merge(arr[i].second, 0);
			ans += arr[i].first;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (find(i) != find(0)) {
			cout << "Oh no";
			return 0;
		}
	}

	cout << ans;

	return 0;
}