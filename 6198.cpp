#include <iostream>
#include <stack>
using namespace std;
using ll = long long;
ll n, ans;
stack <pair<int, int>> st;
/*
10 3 7 4 12 2
답이 21억을 넘어갈 수 있음. 1 ~ 80000의 합
*/
int main() {
	cin >> n;
	for (int i = 1; i <= n + 1; i++) {
		int a;

		if (i != n + 1) cin >> a;
		else a = 2000000000;

		if (st.empty()) st.push({ i,a });
		else {
			if (st.top().second <= a) {
				while (!st.empty() && st.top().second <= a) {
					ans += (i - st.top().first - 1);
					st.pop();
				}
			}

			st.push({ i,a });
		}

	}
	cout << ans;


	return 0;
}