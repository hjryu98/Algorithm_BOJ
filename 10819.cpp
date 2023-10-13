#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int n, arr[10], res[10], ans;
bool check[10];
void recur(int x) {
	if (x >= n) {
		int tmp = 0;
		for (int i = 1; i < n; i++) tmp += abs(res[i] - res[i - 1]);
		ans = max(ans, tmp);
		return;
	}

	for (int i = 0; i < n; i++) {
		if (check[i]) continue;

		check[i] = true;
		res[x] = arr[i];
		recur(x + 1);
		res[x] = 0;
		check[i] = false;
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	recur(0);
	cout << ans;
	return 0;
}