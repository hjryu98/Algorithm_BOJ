#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct comp {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		return min(100 - a.first, a.second) < min(100 - b.first, b.second);
	}
};

priority_queue <pair<int, int>, vector<pair<int, int>>, comp> pq;
int n, m, ans;
int arr[200002];
int brr[200002];
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) cin >> arr[i];
	for (int i = 0; i < m; i++) cin >> brr[i];

	for (int i = 0; i < m; i++) pq.push({ arr[i], brr[i] });

	for (int i = 1; i <= 24 * n; i++) {
		if (pq.empty()) break;

		int a = pq.top().first;
		int b = pq.top().second;
		pq.pop();

		a = min(100, a + b);

		if (a == 100) {
			ans += 100;
			continue;
		}
		pq.push({ a,b });
	}
	while (!pq.empty()) {
		int a = pq.top().first;
		ans += a;
		pq.pop();
	}
	cout << ans;

	return 0;
}