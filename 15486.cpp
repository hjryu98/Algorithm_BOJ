#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <iostream>
#include <algorithm>
using namespace std;
int arr[1500002][2];
int dp[1500002]; //i - 1까지 일했을 때 받는 돈
int n;
int ans, cur;
int main() {
	fastio;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i][0] >> arr[i][1];

	for (int i = 1; i <= n + 1; i++) {
		cur = max(cur, dp[i]);
		if (i + arr[i][0] > n + 1) continue;

		dp[i + arr[i][0]] = max(dp[i + arr[i][0]], cur + arr[i][1]);
		ans = max(ans, dp[i + arr[i][0]]);
	}
	cout << ans;

	return 0;
}