#include <iostream>
#include <vector>
#include <algorithm>
/*
1016boj
*/
using namespace std;
using ll = long long;
ll a, b;
ll ans;
vector <ll> prime;
vector <ll> not_prime;
bool is_not_prime[3200000];

void sieve() {
	is_not_prime[1] = true;

	for (ll i = 2; i < 3200000; i++) {
		if (is_not_prime[i]) continue;
		prime.push_back(i);

		for (ll j = i * 2; j < 3200000; j += i) {
			not_prime.push_back(j);
			is_not_prime[j] = true;
		}
	}
}
/*
1 , 50

2^2 4 8 12 16 20 24 28 32 36 40 44 48
3^2 9 18 27 36 45
5^2 25 50
7^2 49
´ä 31

4^2 16 32 48
6^2 36

*/
int main() {
	cin >> a >> b;

	sieve();

	sort(not_prime.begin(), not_prime.end());

	for (int i = 0; prime[i] * prime[i] <= b; i++) {
		ll val = prime[i];
		if (a % val == 0) {
			ans += (b / (val * val)) - (a / (val * val)) + 1;
		}
		else ans += (b / (val * val)) - (a / (val * val));

		cout << ans << "\n";
	}
	



	cout << (b - a + 1) - ans;

	return 0;
}