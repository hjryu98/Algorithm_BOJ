#include <iostream>
using namespace std;
int n, m;
int a[1000002];
int b[1000002];
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;

	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) cin >> b[i];

	int s1 = 0;
	int s2 = 0;


	while (s1 <= n - 1 && s2 <= m - 1) {
		if (a[s1] > b[s2]) {
			cout << b[s2++] << " ";
		}
		else {
			cout << a[s1++] << " ";
		}
	}

	if (s1 == n) {
		for (int i = s2; i < m; i++) cout << b[i] << " ";
	}
	else {
		for (int i = s1; i < n; i++) cout << a[i] << " ";
	}

	return 0;
}