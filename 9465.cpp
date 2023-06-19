#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int dp[3][100002]; 
int arr[3][100002];
int t;
void init() {
	memset(dp, 0, sizeof(dp));
}

int main() {
	cin >> t;
	while (t--) {
		init();
		int n;
		cin >> n;
		for (int i = 0; i < 2; i++) {
			for (int j = 1; j <= n; j++) cin >> arr[i][j];
		}
		dp[0][1] = arr[0][1], dp[1][1] = arr[1][1];
		dp[0][2] = dp[1][1] + arr[0][2], dp[1][2] = dp[0][1] + arr[1][2];

		for (int i = 3; i <= n; i++) {
			dp[0][i] = max(max(dp[0][i - 2], dp[1][i - 2]), dp[1][i - 1]) + arr[0][i];
			dp[1][i] = max(max(dp[0][i - 2], dp[1][i - 2]), dp[0][i - 1]) + arr[1][i];
		}


		cout << max(dp[0][n], dp[1][n]) << "\n";
	}

	return 0;
}