#include <iostream>
#include <cmath>
using namespace std;
string a;
int n, ans, idx;
int main() {
	cin >> a >> n;

	for (int i = a.size() - 1; i >= 0; i--) {
		char cur = a[i];
		int value = 0;
		if (cur >= 'A' && cur <= 'Z') {
			value = (int)(cur - 'A' + 10);
		}
		else value = (int)(cur - '0');

		ans += value * (int)pow(n, idx++);
	}
	cout << ans;

	return 0;
}