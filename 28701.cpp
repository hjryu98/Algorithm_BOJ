#include <iostream>
using namespace std;
int n, i, sum, sum1;
int main() {
	cin >> n;
	for (i = 1; i <= n; i++) sum += i;
	for (i = 1; i <= n; i++) sum1 += i * i * i;
	cout << sum << "\n" << sum * sum << "\n" << sum1;

	return 0;
}