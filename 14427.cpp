#include <iostream>
#include <algorithm>
using namespace std;
int arr[100005];
pair<int, int> tree[400020]; //first 해당 값, second 인덱스
int n, m;

pair<int, int> init(int node, int s, int e) {
	if (s == e) {
		tree[node].first = arr[s];
		tree[node].second = s;
		return tree[node];
	}

	int mid = (s + e) / 2;
	pair <int, int> left = init(node * 2, s, mid);
	pair <int, int> right = init(node * 2 + 1, mid + 1, e);

	if (left.first > right.first) {
		tree[node].first = right.first;
		tree[node].second = right.second;
	}
	else if (left.first < right.first) {
		tree[node].first = left.first;
		tree[node].second = left.second;
	}
	else {
		if (left.second > right.second) {
			tree[node].first = right.first;
			tree[node].second = right.second;
		}
		else {
			tree[node].first = left.first;
			tree[node].second = left.second;
		}
	}
	return tree[node];
}

pair<int, int> update(int node, int s, int e, int idx, int val) {
	if (idx < s || idx > e) {
		return tree[node];
	}

	if (s == e) {
		tree[node].first = val;
		tree[node].second = idx;
		return tree[node];
	}

	int mid = (s + e) / 2;
	pair <int, int> left = update(node * 2, s, mid, idx, val);
	pair <int, int> right = update(node * 2 + 1, mid + 1, e, idx, val);

	if (left.first > right.first) {
		tree[node].first = right.first;
		tree[node].second = right.second;
	}
	else if (left.first < right.first) {
		tree[node].first = left.first;
		tree[node].second = left.second;
	}
	else {
		if (left.second > right.second) {
			tree[node].first = right.first;
			tree[node].second = right.second;
		}
		else {
			tree[node].first = left.first;
			tree[node].second = left.second;
		}
	}
	return tree[node];
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	init(1, 1, n);
	cin >> m;

	while (m--) {
		int a;
		cin >> a;
		if (a == 1) {
			int b, c;
			cin >> b >> c;
			update(1, 1, n, b, c);
		}
		else {
			cout << tree[1].second << "\n";
		}
	}

	return 0;
}