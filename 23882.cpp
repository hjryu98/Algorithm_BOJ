#include <iostream>
#include <algorithm>
using namespace std;
int n, k, ret;
int arr[10002];
int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	for (int i = n; i >= 1; i--) {
		int last = i;
		int num = -999999999;
		int idx = 0;
		for (int j = 1; j <= last; j++) {
			if (num < arr[j]) {
				idx = j;
				num = arr[j];
			}
		}
		if (last != idx) {
			swap(arr[last], arr[idx]);
			ret++;
			if (ret == k) {
				for (int j = 1; j <= n; j++) cout << arr[j] << " ";
				return 0;
			}
		}
	}
	cout << -1;

	return 0;
}