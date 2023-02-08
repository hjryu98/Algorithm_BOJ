#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
using ll = long long;
stack <pair<ll, ll>> st;
ll n, ans;
int main() {
	cin >> n;
	for (ll i = 1; i <= n; i++) {
		ll a;
		cin >> a;
		if (st.empty()) st.push({ a, i });

		else {
			if (st.top().first >= a) ans += (i - st.top().second + 1);
			else {
				while (!st.empty() && st.top().first < a) {
					ans += (i - st.top().second + 1);
					st.pop();
				}
				if (!st.empty()) ans += (i - st.top().second + 1);
			}
			st.push({ a , i });
		}
	}
	cout << ans;
	return 0;
}