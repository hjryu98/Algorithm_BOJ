#include <iostream>
#include <algorithm>
using namespace std;
int dp[4002][4002];
string a, b;
int main() {
	cin >> a >> b;
	for (int i = 1; i <= a.size(); i++) {
		for (int j = 1; j <= b.size(); j++) {
			if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = 0;
		}
	}
	int val = 0;
	for (int i = 1; i <= a.size(); i++) val = max(val, *max_element(dp[i], dp[i] + b.size() + 1));
	cout << val;

	return 0;
}