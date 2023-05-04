#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
map <int, int> a, b;
int prefix[500002], suffix[500002]; 
int n, h;
vector <int> v;
void init() {
	for (int i = 0; i < 500002; i++) {
		prefix[i] = n / 2;
		suffix[i] = n / 2;
	}
}

int search(int val) {
	int s = 0;
	int e = v.size();

	while (s + 1 < e) {
		int mid = (s + e) / 2;
		if (v[mid] <= val) s = mid;
		else e = mid;
	}
	return s;
}

int main() {
	cin >> n >> h;
	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;

		if (i % 2 != 0) a[num]++; //석순
		
		else b[num]++; //종유석
	}
	init();

	for (int i = 2; i < h; i++) prefix[i] = prefix[i - 1] - a[i - 1];
	for (int i = 2; i < h; i++) suffix[i] = suffix[i - 1] - b[i - 1];

	for (int i = 1; i <= h; i++) {
		if (i == 1 || i == h) v.push_back(n / 2);
		else v.push_back(prefix[i] + suffix[h - i + 1]);
	}
	sort(v.begin(), v.end());
	cout << v[0] << " " << search(v[0]) + 1;

	return 0;
}