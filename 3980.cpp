#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int t, ans;
int arr[13][13];
bool check[13];
void init(){
	memset(arr, 0, sizeof(arr));
	memset(check, false, sizeof(check));
	ans = 0;
}

void recur(int cur, int score) {
	if (cur >= 12) {
		ans = max(ans, score);
		return;
	}

	for (int i = 1; i <= 11; i++) {
		if (check[i]) continue;

		if (!arr[cur][i]) continue;

		check[i] = true;
		recur(cur + 1, score + arr[cur][i]);
		check[i] = false;
	}
}

int main() {
	cin >> t;
	while (t--) {
		init();

		for (int i = 1; i <= 11; i++) {
			for (int j = 1; j <= 11; j++) cin >> arr[i][j];
		}
		recur(1, 0);
		cout << ans << "\n";
	}

	return 0;
}