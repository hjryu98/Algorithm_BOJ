#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <iostream>
#include <set>
using ll = long long;
using namespace std;
set <ll> s;
int n;
ll cnt;
ll total;
ll arr[22];

void recur(int x, int cur, ll sum, int prv) {
	if (cur >= x) {
		s.insert(sum);
		return;
	}

	for (int i = prv; i < n; i++) {
		recur(x, cur + 1, sum + arr[i], i + 1);
	}
}

int main() {
	fastio;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		total += arr[i];
		s.insert(arr[i]);
	}
	s.insert(total);

	for (int i = 2; i <= n - 1; i++) recur(i, 0, 0, 0);

	cout << total - s.size();

	return 0;
}