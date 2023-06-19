#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
using ll = long long;
stack <pair<int, ll>> st;
int n;
ll arr[100003], prefix[100003], suffix[100003], ans;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	for (int i = 1; i <= n; i++) {
		if (st.empty()) st.push({ i, arr[i] });

		else {
			while (!st.empty() && st.top().second > arr[i]) {
				prefix[st.top().first] = i - 1;
				st.pop();
			}
			st.push({ i, arr[i] });
		}
	}
	while (!st.empty()) {
		prefix[st.top().first] = n;
		st.pop();
	}

	for (int i = n; i >= 1; i--) {
		if (st.empty()) st.push({ i, arr[i] });

		else {
			while (!st.empty() && st.top().second > arr[i]) {
				suffix[st.top().first] = i + 1;
				st.pop();
			}
			st.push({ i, arr[i] });
		}
	}
	while (!st.empty()) {
		suffix[st.top().first] = 1;
		st.pop();
	}
	for (int i = 1; i <= n; i++) {
		ans = max(ans, (prefix[i] - suffix[i] + 1) * arr[i]);
	}
	cout << ans << "\n";

	return 0;
}