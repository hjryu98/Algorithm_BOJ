#include <iostream>
using namespace std;
int n;
int dp[50];
int recnt, dpcnt;
int recur(int x) {
	if (x == 1 || x == 2) {
		recnt++;
		return 1;
	}
	return recur(x - 1) + recur(x - 2);
}

int redp(int x) {
	dp[1] = dp[2] = 1;
	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
		dpcnt++;
	}
	return dp[n];
}

int main() {
	cin >> n;

	recur(n);
	redp(n);
	cout << recnt << " " << dpcnt;

	return 0;
}