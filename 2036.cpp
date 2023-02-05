#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
ll ans;
vector <ll> parr;
vector <ll> narr;
int zero, one;
int n;
bool comp(ll a, ll b) {
	return a > b;
}
int main() {
	fastio;
	cin >> n;
	for (int i = 0; i < n; i++) {
		ll a;
		cin >> a;
		if (a > 0) {
			if (a == 1) one++;
			else parr.push_back(a);
		}
		else if (a < 0) narr.push_back(a);
		else zero++;
	}
	sort(parr.begin(), parr.end());
	sort(narr.begin(), narr.end(), comp);

	int psize = parr.size();
	while (psize > 1) {
		ll first = parr[psize - 1];
		ll second = parr[psize - 2];
		psize -= 2;
		parr.pop_back();
		parr.pop_back();
		ans += first * second;
	}
	if (psize >= 1) ans += parr[0];
	ans += one;

	int nsize = narr.size();
	while (nsize > 1) {
		ll first = narr[nsize - 1];
		ll second = narr[nsize - 2];
		nsize -= 2;
		narr.pop_back();
		narr.pop_back();
		ans += first * second;
	}
	if (nsize >= 1) {
		if (zero == 0) ans += narr[0];
	}
	cout << ans;

	return 0;
}