#include <iostream>
using namespace std;
int dp[302][302];
int arr[302][302];
int n, m;

void calc() {
	for (int i = 1; i <= n; i++) dp[i][1] = dp[i - 1][1] + arr[i][1];
	for (int i = 1; i <= m; i++) dp[1][i] = dp[1][i - 1] + arr[1][i];

	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= m; j++) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + arr[i][j];
		}
	}
}


int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) cin >> arr[i][j];
	}
	int k;
	cin >> k;

	calc();

	while (k--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		cout << dp[c][d] - dp[c][b - 1] - dp[a - 1][d] + dp[a - 1][b - 1] << "\n";
	}

	return 0;
}