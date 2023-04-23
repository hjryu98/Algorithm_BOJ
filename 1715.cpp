#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <iostream>
#include <queue>
using namespace std;
priority_queue <int, vector<int>, greater<int> >pq;
int ans;
int main() {
	fastio;
	int n;
	cin >> n;
	while (n--) {
		int a;
		cin >> a;
		pq.push(a);
	}

	while (!pq.empty()) {
		int val = pq.top();
		int val2;
		pq.pop();

		if (pq.empty()) break;

		val2 = pq.top();
		pq.pop();

		ans += (val + val2);
		pq.push(val + val2);
	}
	cout << ans;

	return 0;
}