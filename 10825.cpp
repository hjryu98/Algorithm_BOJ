#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
vector <pair<pair<string, int>, pair<int, int>>> v;

bool comp(pair<pair<string, int>, pair<int, int>> a, pair<pair<string, int>, pair<int, int>> b) {
	if (a.first.second != b.first.second) return a.first.second > b.first.second;
	if (a.second.first != b.second.first) return a.second.first < b.second.first;
	if (a.second.second != b.second.second) return a.second.second > b.second.second;
	return a.first.first.compare(b.first.first) < 0;
}

int main() {
	fastio;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string a;
		int b, c, d;
		cin >> a >> b >> c >> d;
		v.push_back({ {a,b},{c,d} });
	}

	sort(v.begin(), v.end(), comp);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first.first << "\n";
	}
	

	return 0;
}