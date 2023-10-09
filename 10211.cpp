#include <iostream>
#include <algorithm>
using namespace std;
int t;
int main() {
	cin >> t;
	while (t--) {
		int n;
		int arr[1002] = { 0, };
		int dp[1002] = { 0, };
		cin >> n;

		for (int i = 0; i < n; i++) cin >> arr[i];

		dp[0] = arr[0];

		for (int i = 1; i < n; i++) {
			dp[i] = max(dp[i - 1] + arr[i], arr[i]);
		}
		cout << *max_element(dp, dp + n) << "\n";
	}

	return 0;
}