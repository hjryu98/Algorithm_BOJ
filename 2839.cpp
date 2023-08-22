#define inf 999999999
#include <iostream>
#include <algorithm>
using namespace std;
int dp[5002], n;
int main() {
	cin >> n;
	for (int i = 0; i < 5002; i++) dp[i] = inf;
	dp[3] = dp[5] = 1;
	for (int i = 6; i <= n; i++) dp[i] = min(dp[i - 3], dp[i - 5]) + 1;
	cout << ((dp[n] >= inf) ? -1 : dp[n]);

	return 0;
}