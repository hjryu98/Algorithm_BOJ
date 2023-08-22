#include <iostream>
using namespace std;
int t, n, m;

int main() {
	cin >> t;
	while (t--) {
		int arr[25] = { 0, };
		int dp[10002] = { 0, };
		cin >> n;
		for (int i = 0; i < n; i++) cin >> arr[i];
		cin >> m;

		dp[0] = 1;

		for (int i = 0; i < n; i++) {
			for (int j = arr[i]; j <= m; j++) {
				dp[j] += dp[j - arr[i]];
			}
		}
		cout << dp[m] << "\n";

	}

	return 0;
}