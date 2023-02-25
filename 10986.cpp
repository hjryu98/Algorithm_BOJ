#include <iostream>
using namespace std;
using ll = long long;
ll prefix[1005];
ll sum, ans;
int n, m;
/*
(prefix[j] - prefix[i - 1]) % m = 0
prefix[j] % m = prefix[i - 1] % m
�������� ���� �׷쿡�� 2�� ���� + ȥ�ڸ� �ִ� ��� �߰�(0�� ����ؾ� ��)
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