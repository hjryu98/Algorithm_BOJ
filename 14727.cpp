#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
using ll = long long;
ll arr[100002];
ll prefix[100002]; //arr[i]보다 작은 블록 위치 -> 앞
ll suffix[100002]; //뒤
int n;
ll ans;
stack <pair<int, ll>> st;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	for (int i = 1; i <= n; i++) {
		while (!st.empty() && st.top().second > arr[i]) {
			prefix[st.top().first] = i - 1;
			st.pop();
		}
		st.push({ i,arr[i] });
	}
	while (!st.empty()) {
		prefix[st.top().first] = n;
		st.pop();
	}

	for (int i = n; i >= 1; i--) {
		while (!st.empty() && st.top().second > arr[i]) {
			suffix[st.top().first] = i + 1;
			st.pop();
		}
		st.push({ i,arr[i] });
	}
	while (!st.empty()) {
		suffix[st.top().first] = 1;
		st.pop();
	}

	for (int i = 1; i <= n; i++) ans = max(ans, (prefix[i] - suffix[i] + 1) * arr[i]);
	
	cout << ans;

	return 0;
}