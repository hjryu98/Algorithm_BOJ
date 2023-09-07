#include <iostream>
#include <cstring>
using namespace std;
int t, n, m, arr[22], dp[10005];

void init() {
	memset(arr, 0, sizeof(arr));
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
}

int main() {
	cin >> t;
	while (t--) {
		init();
		cin >> n;

		for (int i = 1; i <= n; i++) cin >> arr[i];

		cin >> m;

		for (int i = 1; i <= n; i++) {
			for (int j = arr[i]; j <= m; j++) dp[j] += dp[j - arr[i]];
		}
		cout << dp[m] << "\n";
	}


	return 0;
}