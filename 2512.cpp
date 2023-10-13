#include <iostream>
#include <algorithm>
using namespace std;
int n, arr[10004], m;

bool check(int val) {
	int ans = 0;

	for (int i : arr) {
		if (i < val) ans += i;
		else ans += val;
	}

	return ans <= m;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	cin >> m;

	// 모두 줄 수 있는 경우 예외처리
	int sum = 0;
	for (int i : arr) sum += i;
	if (sum <= m) {
		cout << *max_element(arr, arr + n);
		return 0;
	}

	int s = 1; int e = m + 1;

	while (s + 1 < e) {
		int mid = (s + e) / 2;
		if (check(mid)) s = mid;
		else e = mid;
	}
	cout << s;

	return 0;
}