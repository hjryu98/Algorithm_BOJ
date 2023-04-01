#include <iostream>
#include <algorithm>
using namespace std;
int n;
int ans;
int a[55];
int b[55];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];

	sort(a, a + n);
	sort(b, b + n, greater<int>());

	for (int i = 0; i < n; i++) ans += (a[i] * b[i]);

	cout << ans;
	return 0;
}
