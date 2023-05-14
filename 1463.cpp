#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int dp[1000002];
int n;

int solution(int a) {
	if (a == 1) return 0;
	if (dp[a] != -1) return dp[a];

	int ret = 999999999;

	ret = min(ret, solution(a - 1) + 1);

	if (a % 3 == 0) ret = min(ret, solution(a / 3) + 1);

	if (a % 2 == 0) ret = min(ret, solution(a / 2) + 1);

	return dp[a] = ret;
}
int main() {
	cin >> n;
	memset(dp, -1, sizeof(dp));

	cout << solution(n);
	return 0;
}