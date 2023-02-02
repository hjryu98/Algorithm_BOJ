#include <iostream>
using namespace std;
int n, m;
int arr[1030][1030];
int dp[1030][1030];
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) cin >> arr[i][j];
	}

	for (int i = 1; i <= n; i++) {
		dp[i][1] = dp[i - 1][1] + arr[i][1];
		dp[1][i] = dp[1][i - 1] + arr[1][i];
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= n; j++) {
			dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1] + arr[i][j];
		}
	}

	while (m--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		cout << dp[x2][y2] - dp[x2][y1 - 1] - dp[x1 - 1][y2] + dp[x1 - 1][y1 - 1] << "\n";
	}

	return 0;
}