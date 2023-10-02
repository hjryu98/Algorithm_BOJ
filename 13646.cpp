#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
using ll = long long;
ll n;
vector <ll> prime;
bool is_prime[66000];

void init() {
	for (int i = 0; i < 66000; i++) is_prime[i] = true;
}

void calc() {
	is_prime[1] = false;

	for (int i = 2; i < 66000; i++) {
		if (!is_prime[i]) continue;

		prime.push_back(i);

		for (int j = i * 2; j < 66000; j += i) is_prime[j] = false;
	}
}


ll euler_phi(ll x) {
	ll cnt = x;

	for (int i = 0; i < prime.size(); i++) {
		ll cur = prime[i];
		if (x <= 1) break;

		if (x % cur == 0) {
			while (x % cur == 0) x /= cur;
			cnt = cnt / cur * (cur - 1);
		}
	}
	if (x > 1) cnt = cnt / x * (x - 1);

	return cnt;
}

int main() {
	fastio;
	init();
	calc();

	while (cin >> n) {
		cout << euler_phi(n) / 2 << "\n";
	}

	return 0;
}