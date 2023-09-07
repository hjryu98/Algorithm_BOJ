#include <iostream>
#include <algorithm>
using namespace std;
int n, k;
int dp[100002][105]; //dp[i][j]: ������ �ִ빫�԰� i, j��° ������ ���� ���� �� �ִ� ��ġ
int arr[105][2];
int main() {
	cin >> n >> k;

	for (int i = 1; i <= n; i++) cin >> arr[i][0] >> arr[i][1];

	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n; j++) {
			if (i < arr[j][0]) dp[i][j] = dp[i][j - 1];
			else {
				dp[i][j] = max(dp[i - arr[j][0]][j - 1] + arr[j][1], dp[i][j - 1]);
			}
		}
	}
	cout << dp[k][n];


	return 0;
}