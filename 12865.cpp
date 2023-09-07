#include <iostream>
#include <algorithm>
using namespace std;
int n, k;
int dp[100002][105]; //dp[i][j]: 가방의 최대무게가 i, j번째 물건을 현재 담을 때 최대 가치
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