#include <iostream>
using namespace std;
using ll = long long;
ll prefix[1005];
ll sum, ans;
int n, m;
/*
(prefix[j] - prefix[i - 1]) % m = 0
prefix[j] % m = prefix[i - 1] % m
나머지가 같은 그룹에서 2개 조합 + 혼자만 있는 경우 추가(0도 고려해야 함)
*/
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		sum += a;
		prefix[sum % m]++;
	}

	for (int i = 0; i <= 1000; i++) {
		ans += (prefix[i] * (prefix[i] - 1) / 2);
	}
	cout << ans + prefix[0];

	return 0;
}