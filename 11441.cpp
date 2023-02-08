#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <iostream>
using namespace std;
int n, m;
int prefix[100005];
int main() {
	fastio;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		prefix[i] = prefix[i - 1] + a;
	}

	cin >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		cout << prefix[b] - prefix[a - 1] << "\n";
	}

	return 0;
}