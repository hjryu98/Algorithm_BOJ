#include <iostream>
using namespace std;
int n, ans;
bool flag;
int res[12];
void recur(int x, int cnt) {
	if (flag) return;

	if (x >= 2) {
		if (res[x - 2] <= res[x - 1]) return;
	}

	if (x >= cnt) {
		ans++;

		if (ans == n) {
			for (int i = 0; i < x; i++) cout << res[i];
			flag = true;
		}
		return;
	}

	for (int i = 0; i <= 9; i++) {
		if (x == 0 && i == 0) continue;
		res[x] = i;
		recur(x + 1, cnt);
		res[x] = 0;
	}
}

int main() {
	cin >> n;

	if (n <= 9) {
		cout << n;
		return 0;
	}

	ans = 9;

	for (int i = 2; i <= 10; i++) {
		recur(0, i);
		if (flag) break;
	}
	if (!flag) cout << -1;

	return 0;
}
