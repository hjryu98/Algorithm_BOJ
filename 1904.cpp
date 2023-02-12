#define mod 15746
#include <iostream>
using namespace std;
using ll = long long;
ll dp[1000005];
int n;
int main() {
	cin >> n;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 2] + dp[i - 1]) % mod;
	}
	cout << dp[n];

	return 0;
}