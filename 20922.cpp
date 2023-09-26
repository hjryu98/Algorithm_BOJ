#include <iostream>
#include <algorithm>
using namespace std;
int cnt[100002];
int n, k, arr[200002], ans;
int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	int s = 1;
	int e = 2;
	cnt[arr[1]] = 1;
	ans = max(ans, e - s);

	while (s <= e && (e <= n && s <= n)) {
		if (cnt[arr[e]] >= k) {
			cnt[arr[s]]--;
			s++;
		}
		else {
			cnt[arr[e]]++;
			e++;
		}
		ans = max(ans, e - s);
	}
	cout << ans;


	return 0;
}