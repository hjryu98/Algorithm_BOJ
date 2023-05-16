#include <iostream>
using namespace std;
int n;
int gap[100002];
int arr[100002];
int gcd(int a, int b) {
	while (b) {
		int tmp = a;
		a = b;
		b = tmp % b;
	}
	return a;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	for (int i = 1; i < n; i++) gap[i] = arr[i + 1] - arr[i];

	int val = gap[1];
	for (int i = 2; i < n; i++) val = gcd(val, gap[i]);
	
	cout << (arr[n] - arr[1]) / val + 1 - n;
	return 0;
}