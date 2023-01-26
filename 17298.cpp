#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
int n;
int arr[1000005];
stack <pair<int, int>> st;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (st.empty()) st.push({ a , i });

		else {
			if (a > st.top().first) {
				while (!st.empty() && st.top().first < a) {
					arr[st.top().second] = a;
					st.pop();
				}
			}
			st.push({ a, i });
		}
	}

	for (int i = 0; i < n; i++) {
		if (arr[i] == 0) cout << -1 << " ";
		else cout << arr[i] << " ";
	}

	return 0;
}