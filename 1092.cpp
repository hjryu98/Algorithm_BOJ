#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <iostream>
#include <vector>
#include <algorithm>
//time complexity : approxi. n^2*m
using namespace std;
int n, m, ans;
vector <int> box, crane; //box, crane
int main() {
	fastio;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		crane.push_back(a);
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;
		box.push_back(a);
	}
	sort(crane.begin(), crane.end(), greater<int>());
	sort(box.begin(), box.end(), greater<int>());

	if (crane[0] < box[0]) { cout << -1; return 0; }

	while (!box.empty()) {
		for (int i = 0; i < crane.size(); i++) {
			for (int j = 0; j < box.size(); j++) {
				if (crane[i] >= box[j]) {
					box.erase(box.begin() + j);
					break;
				}
			}
		}
		ans++;
	}
	cout << ans;


	return 0;
}