#include <iostream>
using namespace std;
int n, k, ans;
int arr[210];
bool present[110];

void rotate() {
	int tmp[210] = { 0, };

	for (int i = 1; i <= 2 * n - 1; i++) tmp[i + 1] = arr[i];

	tmp[1] = arr[2 * n];

	for (int i = 1; i <= 2 * n; i++) arr[i] = tmp[i];
}

void prerotate() {
	bool tmp[110] = { 0, };

	for (int i = 1; i <= n - 1; i++) tmp[i + 1] = present[i];

	for (int i = 1; i <= n - 1; i++) present[i] = tmp[i];

	if (present[n]) present[n] = false;
}

int check() {
	int sum = 0;
	for (int i = 1; i <= 2 * n; i++) if (!arr[i]) sum++;

	return sum;
}

void moving() {
	for (int i = n - 1; i >= 1; i--) {
		if (!present[i]) continue;

		if (arr[i + 1] >= 1 && !present[i + 1]) {
			present[i] = false;
			present[i + 1] = true;
			arr[i + 1]--;
		}
	}
}

void solve() {
	while (1) {
		rotate();
		prerotate();

		moving();

		if (arr[1] != 0 && !present[1]) { 
			present[1] = true;
			arr[1]--;
		}

		ans++; 

		if (check() >= k) break; 
	}
	cout << ans;
}

int main() {
	cin >> n >> k;

	for (int i = 1; i <= 2 * n; i++) cin >> arr[i];

	solve();

	return 0;
}