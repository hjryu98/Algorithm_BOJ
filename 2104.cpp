#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
using ll = long long;
int n;
ll arr[100002], pref[100002], suff[100002], prefsum[100002], ans;
stack <pair<int, ll>> st; // idx value
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		prefsum[i] = prefsum[i - 1] + arr[i];
	}

	for (int i = 1; i <= n; i++) {
		if (st.empty()) st.push({ i, arr[i] });

		else {
			while (!st.empty() && st.top().second > arr[i]) {
				pref[st.top().first] = i - 1;
				st.pop();
			}
			st.push({ i, arr[i] });
		}
	}
	while (!st.empty()) {
		pref[st.top().first] = n;
		st.pop();
	}

	for (int i = n; i >= 1; i--) {
		if (st.empty()) st.push({ i, arr[i] });
		else {
			while (!st.empty() && st.top().second > arr[i]) {
				suff[st.top().first] = i + 1;
				st.pop();
			}
			st.push({ i, arr[i] });
		}
	}
	while (!st.empty()) {
		suff[st.top().first] = 1;
		st.pop();
	}

	for (int i = 1; i <= n; i++) {
		ll len = prefsum[pref[i]] - prefsum[suff[i] - 1];
		ans = max(ans, len * arr[i]);
	}
	cout << ans;

	return 0;
}