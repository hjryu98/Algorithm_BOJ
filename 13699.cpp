#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
ll dp[40];
int n;

int main() {
	cin >> n;
	dp[1] = dp[0] = 1;
	dp[2] = 2;
	dp[3] = 5;

	for (int i = 4; i <= n; i++) {
		for (int j = 0; j < n; j++) {
			dp[i] += (dp[j] * dp[i - 1 - j]);
		}
	}
	cout << dp[n];

	return 0;
}