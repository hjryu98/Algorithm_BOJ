#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
int a, b;
int barr[500002];
int q[500002];
set <int> ss;
vector <int> ans;
int main() {
	fastio;
	cin >> a >> b;

	for (int i = 0; i < a; i++) cin >> q[i];
	for (int i = 0; i < b; i++) cin >> barr[i];
	sort(barr, barr + b);

	for (int i = 0; i < a; i++) {
		int val = q[i];
		int s = 0;
		int e = b - 1;
		//2 5 7 11
		while (s <= e) {
			int mid = (s + e) / 2;

			if (barr[mid] < val) s = mid + 1;
			else if (barr[mid] > val) e = mid - 1;
			else {
				ss.insert(val);
				break;
			}
		}
	}

	for (int i = 0; i < a; i++) {
		if (ss.count(q[i])) continue;
		ans.push_back(q[i]);
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";

	return 0;
}