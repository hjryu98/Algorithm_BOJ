#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
int n;
ll ans;
int arr[10005];

int ffind(int s, int e, int val) {
	if (val < arr[s - 1] || arr[e] < val) return -1;

	if (val == arr[s]) return s;

	while (s + 1 < e) {
		int mid = (s + e) / 2;

		if (arr[mid] >= val) e = mid;
		else s = mid;
	}
	if (arr[e] == val) return e;
	else return -1;
}

int rfind(int s, int e, int val) {
	if (val < arr[s - 1] || arr[e] < val) return -1;

	if (val == arr[e]) return e;

	while (s + 1 < e) {
		int mid = (s + e) / 2;

		if (arr[mid] <= val) s = mid;
		else e = mid;
	}
	if (arr[s] == val) return s;
	else return -1;
}


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	sort(arr, arr + n);

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int cur = arr[i] + arr[j];

			int f = ffind(j + 1, n - 1, -1 * cur);
			int r = rfind(j + 1, n - 1, -1 * cur);
			if (f == -1 || r == -1) continue;
			ans += (r - f + 1);
		}
	}
	cout << ans;

	return 0;
}