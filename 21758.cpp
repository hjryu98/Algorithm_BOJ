#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <iostream>
#include <algorithm>
using ll = long long;
using namespace std;
ll prefix[100002], suffix[100002], arr[100002];
ll ans;
int n;

int main() {
	fastio;

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	for (int i = 1; i <= n; i++) prefix[i] = prefix[i - 1] + arr[i];
	for (int i = 1; i <= n; i++) suffix[i] = suffix[i - 1] + arr[n + 1 - i];

	for (int i = 2; i < n; i++) ans = max(ans, prefix[n] - prefix[i] + prefix[n] - prefix[1] - arr[i]); //통이 맨 오른쪽

	for (int i = 2; i < n; i++) ans = max(ans, suffix[n] - suffix[i] + suffix[n] - suffix[1] - arr[n - i + 1]); //통이 맨 왼쪽

	for (int i = 2; i < n; i++) ans = max(ans, prefix[i] - prefix[1] + suffix[n - i + 1] - suffix[1]); //가운데

	cout << ans;

	return 0;
}