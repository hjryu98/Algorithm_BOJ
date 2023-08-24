#define mod 1000000007
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
ll dp[100005]; // dp[i]: i와 그 부모노드를 잇는 간선이 이용된 횟수
int n, arr[100005], ans;
vector <int> v[100005];

int subtree(int cur) {
	dp[cur] = 1;

	for (int i = 0; i < v[cur].size(); i++) {
		if (!dp[v[cur][i]]) {
			dp[cur] += subtree(v[cur][i]);
		}
	}
	return dp[cur];
}

int main() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i < n; i++) cin >> arr[i];

	subtree(1);

	for (int i = 1; i <= n; i++) dp[i] *= (n - dp[i]);

	sort(dp + 1, dp + n + 1, greater<ll>());
	sort(arr, arr + n);

	for (int i = 1; i < n; i++) {
		ans = (ans + dp[i] * arr[i]) % mod;
	}
	cout << ans;


	return 0;
}