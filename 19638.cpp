#include <iostream>
#include <queue>
using namespace std;
priority_queue <int> pq;
int n, centi, t;
int ans;
bool flag = true;
int main() {
	cin >> n >> centi >> t;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (a >= centi) pq.push(a);
		if (a == 1) flag = false;
	}
	if (centi == 1 && !flag) {
		cout << "NO\n" << pq.top();
		return 0;
	}

	while (t--) {
		if (pq.empty()) break;

		int cur = pq.top();
		pq.pop();
		cur /= 2;
		ans++;

		if (cur < centi) continue;

		pq.push(cur);
	}

	if (pq.empty()) {
		cout << "YES\n" << ans;
	}
	else {
		cout << "NO\n" << pq.top();
	}


	return 0;
}