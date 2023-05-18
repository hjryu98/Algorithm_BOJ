#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
using ll = long long;
int n, i;
ll ans;
int arr[1000002];
ll index[1000002][2];
stack <pair<int, ll>> st;
int main() {
	fastio;
	cin >> n;
	for (i = 1; i <= n; i++) cin >> arr[i];

	for (i = 1; i <= n; i++) {
		while (!st.empty() && st.top().second > arr[i]) {
			index[st.top().first][0] = i - 1;
			st.pop();
		}
		st.push({ i, arr[i] });
	}
	while (!st.empty()) {
		index[st.top().first][0] = n;
		st.pop();
	}

	for (i = n; i >= 1; i--) {
		while (!st.empty() && st.top().second > arr[i]) {
			index[st.top().first][1] = i + 1;
			st.pop();
		}
		st.push({ i, arr[i] });
	}
	while (!st.empty()) {
		index[st.top().first][1] = 1;
		st.pop();
	}

	for (i = 1; i <= n; i++) ans = max(ans, (index[i][0] - index[i][1] + 1) * arr[i]);
	cout << ans;
	return 0;
}