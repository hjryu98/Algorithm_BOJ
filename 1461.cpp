#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int n, m, arr[55], ans;
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];

	sort(arr, arr + 1 + n);

	int center = 0;
	for (int i = 0; i <= n; i++) {
		if (!arr[i]) {
			center = i;
			break;
		}
	}

	for (int i = 0; i < center; i += m) {
		ans += (abs(arr[i]) * 2);
	}

	for (int i = n; i > center; i -= m) {
		ans += (abs(arr[i]) * 2);
	}

	ans -= max(abs(arr[0]), abs(arr[n]));
	cout << ans;

	return 0;
}