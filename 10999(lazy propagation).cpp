#include <iostream> //lazy propagation
using namespace std;
using ll = long long;
ll arr[1000005], tree[4000020], lazy[4000020];
int n, m, k;

void check(int node, int s, int e) {
	if (lazy[node]) {
		tree[node] += (ll)(e - s + 1) * lazy[node];

		if (s != e) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

ll init(int node, int s, int e) {
	if (s == e) return tree[node] = arr[s];

	int mid = (s + e) / 2;
	return tree[node] = init(node * 2, s, mid) + init(node * 2 + 1, mid + 1, e);
}

ll update(int node, int s, int e, int l, int r, ll val) {
	check(node, s, e);

	if (r < s || e < l) return tree[node];

	if (l <= s && e <= r) {
		lazy[node] += val;
		check(node, s, e);
		return tree[node];
	}
	int mid = (s + e) / 2;
	return tree[node] = update(node * 2, s, mid, l, r, val) + update(node * 2 + 1, mid + 1, e, l, r, val);
}

ll query(int node, int s, int e, int l, int r) {
	check(node, s, e);

	if (r < s || e < l) return 0;

	if (l <= s && e <= r) return tree[node];

	int mid = (s + e) / 2;
	return query(node * 2, s, mid, l, r) + query(node * 2 + 1, mid + 1, e, l, r);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	int cnt = m + k;
	init(1, 1, n);
	while (cnt--) {
		int a;
		cin >> a;
		if (a == 1) {
			int b, c;
			ll d;
			cin >> b >> c >> d;
			update(1, 1, n, b, c, d);
		}
		else {
			int b, c;
			cin >> b >> c;
			cout << query(1, 1, n, b, c) << "\n";
		}
	}
	
	return 0;
}