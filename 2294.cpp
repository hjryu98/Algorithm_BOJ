#define inf 999999999
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int n, k;
vector <int> v;
set <int> st;
int dp[10005];
int main() {
	cin >> n >> k;
	for (int i = 0; i < 10005; i++) dp[i] = inf;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (st.count(a)) continue;
		v.push_back(a);
		st.insert(a);
	}

	for (int i = 1; i <= k; i++) {
		for (int j = 0; j < v.size(); j++) {
			int ret = i - v[j];
			if (ret < 0) continue;
			if (!ret) {
				dp[i] = 1;
				break;
			}
			else {
				dp[i] = min(dp[i], dp[ret] + 1);
			}
		}
	}
	cout << ((dp[k] >= inf) ? -1 : dp[k]);

	return 0;
}