#include <iostream>
using namespace std;
int n;
int lc[100002];
int rc[100002];

int recur(int cur) {
	if (rc[cur] == -1) return 0;

	return recur(rc[cur]) + 1;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		lc[a] = b;
		rc[a] = c;
	}
	cout << 2 * (n - 1) - recur(1);

	return 0;
}