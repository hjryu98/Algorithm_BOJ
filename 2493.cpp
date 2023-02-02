#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
stack <pair<int, int>> st;
int n;
int res[500002];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		if (st.empty()) st.push({ a,i });
		else {
			if (st.top().first > a) {
				res[i] = st.top().second;
				st.push({ a, i });
			}
			else {
				while (!st.empty() && st.top().first < a) {
					st.pop();
				}
				if (!st.empty()) res[i] = st.top().second;
				st.push({ a, i });
			}
		}
	}
	for (int i = 1; i <= n; i++) cout << res[i] << " ";

	return 0;
}