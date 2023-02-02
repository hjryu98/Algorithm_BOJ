#include <iostream>
using namespace std;
using ll = long long;
int n, m;
int mx, ans = -1;
ll arr[12];

int getbit(ll x) {
	int cnt = 0;

	while (x) {
		cnt++;
		x -= (x & (-x));
	}
	return cnt;
}

void recur(int cnt, int cur, ll bit) {
	if (cnt >= n) {
		int val = getbit(bit);
		if (val > mx) {
			mx = val;
			ans = cur;
		}
		else if (val == mx) ans = min(ans, cur);
		return;
	}

	recur(cnt + 1, cur + 1, bit | arr[cnt]);
	recur(cnt + 1, cur, bit);
}


int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string a, b;
		cin >> a >> b;

		for (int j = 0; j < b.size(); j++) if (b[j] == 'Y') arr[i] |= (1LL << j);
	}

	recur(0, 0, 0);
	cout << ans;

	return 0;
}