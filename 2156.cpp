#include <iostream>
#include <algorithm>
using namespace std;
int n, dp[10005], arr[10005];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];

	for (int i = 3; i <= n; i++) {
		dp[i] = max(max(dp[i - 1], dp[i - 2] + arr[i]), dp[i - 3] + arr[i] + arr[i - 1]);
	}
	cout << dp[n];

	return 0;
}