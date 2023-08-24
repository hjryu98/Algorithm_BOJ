#include <iostream>
#include <vector>
using namespace std;
int dp[40005], n;
bool is_not_prime[40005];
vector <int> prime;
void get_prime() {
	is_not_prime[1] = true;

	for (int i = 2; i < 40005; i++) {
		if (is_not_prime[i]) continue;
		for (int j = i * 2; j < 40005; j += i) is_not_prime[j] = true;
	}
	for (int i = 2; i < 40005; i++) {
		if (!is_not_prime[i]) prime.push_back(i);
	}
}

int main() {
	get_prime();

	cin >> n;

	dp[0] = 1;

	for (int i = 0; i < prime.size(); i++) {
		for (int j = prime[i]; j <= n; j++) {
			dp[j] = (dp[j] + dp[j - prime[i]]) % 123456789;
		}
	}
	cout << dp[n];

	return 0;
}