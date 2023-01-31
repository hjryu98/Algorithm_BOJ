#include <iostream>
using namespace std;
using ll = long long;
bool check[1000002];
ll a, b, ans;
int main() {
	cin >> a >> b;

	for (ll i = 2; i * i <= b; i++) {
		ll val = a / (i * i);

		if (a % (i * i) != 0) val++;

		while (val * i * i <= b) {
			check[val * i * i - a] = true;
			val++;
		}
	}

	for (ll i = 0; i <= b - a; i++) ans += check[i];
	cout << (b - a + 1) - ans;

	return 0;
}