#include <iostream>
#include <algorithm>
using namespace std;
int n, arr[100002], dp[100002][2], ans;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	ans = arr[1];
	for (int i = 1; i <= n; i++) {
		dp[i][0] = dp[i][1] = arr[i];
		if (i == 1) continue;

		dp[i][0] = max(dp[i - 1][0] + arr[i], arr[i]);
		dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + arr[i]);
		ans = max(ans, max(dp[i][0], dp[i][1]));
	}
	cout << ans;

	return 0;
}