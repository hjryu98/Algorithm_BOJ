#include <iostream>
using namespace std;
using ll = long long;
int n, ans;
int main() {
	cin >> n;

	if (n == 1 || n == 2) {
		cout << 1;
		return 0;
	}

	ll s = 1;
	ll e = 1;

	ll cur = s;
	while (s <= e && e <= n) {
		if (cur > n) cur -= s++;
		else if (cur < n) {
			e++;
			cur += e;
		}
		else {
			ans++;
			cur -= s++;
		}
	}
	cout << ans;

	return 0;
}