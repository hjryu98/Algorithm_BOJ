#include <iostream>
#include <algorithm>
using namespace std;
int n, dp[100002], arr[100002];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	
	for (int i = 1; i <= n; i++) dp[i] = max(dp[i - 1] + arr[i], arr[i]);

	cout << *max_element(dp + 1, dp + 1 + n);

	return 0;
}