#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n;
int arr[1005];
int dp[1005];

void init() {
	for (int i = 0; i < 1005; i++) dp[i] = 999999999;
	dp[1] = 0;
}

int main() {
	init();
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	for (int i = 1; i <= n; i++) {
		//if (dp[i] >= 999999999) continue;
		for (int j = 1; j <= arr[i]; j++) {
			dp[i + j] = min(dp[i + j], dp[i] + 1);
		}
	}
	cout << ((dp[n] >= 999999999) ? -1 : dp[n]);

	return 0;
}