#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
ll n, m;
ll ans;
ll arr[100002];

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	sort(arr + 1, arr + 1 + n);
	ll s = 0;
	ll e = arr[n] * m;
	
	while (s + 1 < e) {
		ll mid = (s + e) / 2;
		ll cnt = 0;
		for (int i = 1; i <= n; i++) {
			cnt += (mid / arr[i]);
			if (cnt >= m) break; ////
		}
		if (cnt >= m) e = mid;
		else s = mid;
	}
	cout << e;

	return 0;
}  