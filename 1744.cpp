#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> parr;
vector <int> narr;
int zero, one;
int n;
int ans;

bool comp(int a, int b) {
	return a > b;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (a > 0) {
			if (a != 1) parr.push_back(a);
			else one++;
		}
		else if (a < 0) narr.push_back(a);
		else zero++;
	}

	sort(narr.begin(), narr.end(), comp);
	sort(parr.begin(), parr.end());

	int psize = parr.size();
	int nsize = narr.size();

	while (psize > 1) {
		int first = parr[psize - 1];
		int second = parr[psize - 2];
		parr.pop_back();
		parr.pop_back();
		psize -= 2;

		ans += (first * second);
	}

	if (psize >= 1) ans += parr[0];
	ans += one;

	while (nsize > 1) {
		int first = narr[nsize - 1];
		int second = narr[nsize - 2];
		narr.pop_back();
		narr.pop_back();
		nsize -= 2;

		ans += (first * second);
	}

	if (nsize >= 1) {
		if (zero <= 0) ans += narr[0];
	}

	cout << ans;

	return 0;
}
