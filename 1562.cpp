#define mod 1000000000
#include <iostream>
using namespace std;
using ll = long long;
int n;
ll dp[102][11][1 << 10];
ll ans;

void solve() {
	int full = (1 << 10) - 1;

	for (int i = 1; i <= 9; i++) dp[1][i][1 << i] = 1;

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = 0; k < (1 << 10); k++) {
				int cur = k | (1 << j);

				if (j == 0) dp[i][j][cur] = (dp[i][j][cur] + dp[i - 1][1][k]) % mod;
				else if (j == 9) dp[i][j][cur] = (dp[i][j][cur] + dp[i - 1][8][k]) % mod;
				else {
					dp[i][j][cur] = (dp[i][j][cur] + dp[i - 1][j - 1][k]) % mod;
					dp[i][j][cur] = (dp[i][j][cur] + dp[i - 1][j + 1][k]) % mod;
				}
			}
		}
	}

	for (int i = 0; i <= 9; i++) ans = (ans + dp[n][i][full]) % mod;
	
	cout << ans;

}

int main() {
	cin >> n;

	solve();

	return 0;
}