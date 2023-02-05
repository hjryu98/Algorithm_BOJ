#include <iostream>
using namespace std;
int n;
int ans;
int res[12];
bool flag;

bool go(int x) {
	if (x <= 1) return true;

	return res[x - 1] < res[x - 2];
}

void recur(int cnt, int cur) {
	if (flag) return;

	if (!go(cur)) return;

	if (cur >= cnt) {
		ans++;
		if (ans == n) {
			for (int i = 0; i < cur; i++) cout << res[i];
			flag = true;
			return;
		}
		return;
	}

	for (int i = 0; i <= 9; i++) {
		if (cur == 0 && i == 0) continue;

		res[cur] = i;
		recur(cnt, cur + 1);
		res[cur] = 0;
	}
}

int main() {
	cin >> n;
	if (n <= 10) {
		cout << n - 1;
		return 0;
	}
	ans = 10;

	for (int i = 2; i <= 10; i++) {
		recur(i, 0);
		if (flag) return 0;
	}
	cout << -1;
	return 0;
}