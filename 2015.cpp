#include <iostream>
#include <map>
using namespace std;
using ll = long long;
map <ll, ll> m;
ll prefix[200003];
ll ans;
int n, k;

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		ll a;
		cin >> a;
		prefix[i] = prefix[i - 1] + a;
	}
	for (int i = 0; i <= n; i++) {
		ans += m[prefix[i] - k];
		m[prefix[i]]++;
	}
	cout << ans;

	return 0;
}