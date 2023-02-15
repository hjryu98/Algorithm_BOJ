#include <iostream>
#include <algorithm>
using namespace std;
int n, c;
int arr[200005];

bool check(int x) {
	int cnt = 1;
	int cur = arr[0];

	for (int i = 1; i < n; i++) {
		int dist = arr[i] - cur;

		if (dist < x) continue;

		cnt++;
		cur = arr[i];
	}
	return cnt >= c;
}

int main() {
	cin >> n >> c;

	for (int i = 0; i < n; i++) cin >> arr[i];

	sort(arr, arr + n);

	int s = 1;
	int e = arr[n - 1] + 1;

	while (s + 1 < e) {
		int mid = (s + e) / 2;

		if (check(mid)) s = mid;
		else e = mid;
	}
	cout << s;

	return 0;
}