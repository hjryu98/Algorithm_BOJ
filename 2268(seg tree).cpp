#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
ll arr[1000005];
ll tree[4000020];
int n, m;

ll init(int node, int s, int e) {
	if (s == e) return tree[node];

	int mid = (s + e) / 2;
	return tree[node] = init(node * 2, s, mid) + init(node * 2 + 1, mid + 1, e);
}

ll query(int node, int s, int e, int l, int r) {
	if (r < s || e < l) return 0;

	if (l <= s && e <= r) return tree[node];

	int mid = (s + e) / 2;
	return query(node * 2, s, mid, l, r) + query(node * 2 + 1, mid + 1, e, l, r);
}
ll update(int node, int s, int e, int idx, ll val) {
	if (idx < s || e < idx) return tree[node];

	if (s == e) return tree[node] = val;

	int mid = (s + e) / 2;

	return tree[node] = update(node * 2, s, mid, idx, val) + update(node * 2 + 1, mid + 1, e, idx, val);
}


int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	
	init(1, 1, n);
	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;
		if (a == 0) {
			int b, c;
			cin >> b >> c;
			if (b > c) swap(b, c);

			cout << query(1, 1, n, b, c) << "\n";
		}

		else {
			int b;
			ll c;
			cin >> b >> c;
			update(1, 1, n, b, c);
		}
	}

	return 0;
}