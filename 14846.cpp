#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <iostream>
using namespace std;
int prefix[305][305][12];
int n, q;
int arr[305][305];

void calc() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 10; j++) {
			if (arr[1][i] == j) prefix[1][i][j] = prefix[1][i - 1][j] + 1;
			else prefix[1][i][j] = prefix[1][i - 1][j];

			if (arr[i][1] == j) prefix[i][1][j] = prefix[i - 1][1][j] + 1;
			else prefix[i][1][j] = prefix[i - 1][1][j];
		}
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= n; j++) {
			for (int k = 1; k <= 10; k++) {
				if (arr[i][j] == k) prefix[i][j][k] = prefix[i - 1][j][k] + prefix[i][j - 1][k] - prefix[i - 1][j - 1][k] + 1;
				else prefix[i][j][k] = prefix[i - 1][j][k] + prefix[i][j - 1][k] - prefix[i - 1][j - 1][k];
			}
		}
	}
}

int main() {
	fastio;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) cin >> arr[i][j];
	}

	calc();

	cin >> q;
	while (q--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		int cnt = 0;

		for (int i = 1; i <= 10; i++) {
			if (prefix[c][d][i] - prefix[c][b - 1][i] - prefix[a - 1][d][i] + prefix[a - 1][b - 1][i]) cnt++;
		}
		cout << cnt << "\n";
	}

	return 0;
}