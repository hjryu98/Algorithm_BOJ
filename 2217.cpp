#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, ans;
vector <int> v;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		ans = max(ans, v[i] * (n - i));
	}
	cout << ans;

	return 0;
}