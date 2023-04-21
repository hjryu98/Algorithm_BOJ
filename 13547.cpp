#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
//mo's & offline-query
using namespace std;
vector <pair<pair<int, int>,int>> q;
int n, m, cnt[1000005], arr[100005], res[100005], cur;

bool comp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
	int val = sqrt(n);

	if (a.first.first / val != b.first.first / val) return a.first.first / val < b.first.first / val;
	return a.first.second < b.first.second;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		q.push_back({ {a,b},i });
	}
	sort(q.begin(), q.end(), comp);

	int s = q[0].first.first;
	int e = q[0].first.second;
	int num = q[0].second;
	for (int i = s; i <= e; i++) {
		if (cnt[arr[i]]++ == 0) cur++;
	}
	res[num] = cur;

	for (int i = 1; i < m; i++) {
		int cs = q[i].first.first;
		int ce = q[i].first.second;
		int cnum = q[i].second;

		while (s < cs) if (--cnt[arr[s++]] == 0) cur--;
		while (s > cs) if (cnt[arr[--s]]++ == 0) cur++;
		while (e < ce) if (cnt[arr[++e]]++ == 0) cur++;
		while (e > ce) if (--cnt[arr[e--]] == 0) cur--;

		res[cnum] = cur;
	}

	for (int i = 0; i < m; i++) cout << res[i] << "\n";

	return 0;
}