#include <iostream>
#include <cmath>
using namespace std;
int n;
int ans = 2000000005;
int arr[100005];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	int s = 1;
	int e = n;
	while (s < e) {
		int cur = arr[s] + arr[e];

		if (abs(ans) > abs(cur)) {
			ans = cur;
			if (ans > 0) e--;
			else if (ans < 0) s++;
			else break;
		}
		else {
			if (cur > 0) e--;
			else if (cur < 0) s++;
		}
	}
	cout << ans;

	return 0;
}