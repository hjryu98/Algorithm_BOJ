#include <iostream>
using namespace std;
int t;
int dp[16][16];
void init() {
	for (int i = 0; i < 15; i++) {
		for (int j = 1; j < 15; j++) {
			if (!i) dp[i][j] = j;
			else {
				if (j == 1) dp[i][j] = 1;
				else {
					dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
				}
			}
		}
	}
}

int main() {
	cin >> t;
	init();
	while (t--) {
		int k, n;
		cin >> k >> n;
		cout << dp[k][n] << "\n";
	}


	return 0;
}