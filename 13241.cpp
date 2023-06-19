#include <iostream>
using namespace std;
using ll = long long;
ll a, b;

ll gcd(ll a, ll b) {
	while (b) {
		ll tmp = a;
		a = b;
		b = tmp % b;
	}
	return a;
}

int main() {
	cin >> a >> b;
	cout << a * b / gcd(a, b) << "\n";
	return 0;
}