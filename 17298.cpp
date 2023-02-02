#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
int n;
int res[1000002];
stack <pair<int, int>> st;
int main() {
	fastio;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		if (st.empty()) st.push({ a, i });
		else {
			if (st.top().first < a) {
				while (!st.empty() && st.top().first < a) {
					res[st.top().second] = a;
					st.pop();
				}
			}
			st.push({ a, i });
		}
	}
	for (int i = 1; i <= n; i++) {
		if (res[i] == 0) cout << -1 << " ";
		else cout << res[i] << " ";
	}

	return 0;
}