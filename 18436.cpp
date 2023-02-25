#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <iostream>
using namespace std;
int arr[100005];
pair<int, int> tree[400020];
int n, m;

pair<int, int> init(int node, int s, int e) {
	if (s == e) {
		if (arr[s] % 2 != 0) tree[node].second++;
		else tree[node].first++;
		return tree[node];
	}

	int mid = (s + e) / 2;
	pair<int, int> left = init(node * 2, s, mid);
	pair<int, int> right = init(node * 2 + 1, mid + 1, e);
	tree[node].first = left.first + right.first;
	tree[node].second = left.second + right.second;
	return tree[node];
}

pair<int, int> update(int node, int s, int e, int idx, int val) {
	if (idx < s || idx > e) return tree[node];

	if (s == e) {
		if (arr[s] % 2 == 0) tree[node].first--;
		else tree[node].second--;
		arr[s] = val;

		if (val % 2 != 0) {
			tree[node].second++;		
		}
		else {
			tree[node].first++;
		}
		return tree[node];
	}

	int mid = (s + e) / 2;
	pair<int, int> left = update(node * 2, s, mid, idx, val);
	pair<int, int> right = update(node * 2 + 1, mid + 1, e, idx, val);
	tree[node].first = left.first + right.first;
	tree[node].second = left.second + right.second;
	return tree[node];
}

pair<int, int> query(int node, int s, int e, int l, int r) {
	if (r < s || l > e) return { 0, 0 };

	if (l <= s && e <= r) return tree[node];

	int mid = (s + e) / 2;
	pair<int, int> left = query(node * 2, s, mid, l, r);
	pair<int, int> right = query(node * 2 + 1, mid + 1, e, l, r);
	int evenret = left.first + right.first;
	int oddret = left.second + right.second;
	return { evenret, oddret };
}

int main() {
	fastio;

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	init(1, 1, n);

	cin >> m;
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) update(1, 1, n, b, c);
		else if (a == 2) cout << query(1, 1, n, b, c).first << "\n";
		else cout << query(1, 1, n, b, c).second << "\n";
	}

	return 0;
}