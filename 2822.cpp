#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
vector <pair<int,int>> v;
set <int> s;
bool comp(pair<int, int> a, pair<int, int> b) {
	if (a.first != b.first) return a.first > b.first;
	return a.second < b.second;
}

int main() {
	for (int i = 0; i < 8; i++) {
		int a;
		cin >> a;
		v.push_back({ a,i });
	}
	sort(v.begin(), v.end(), comp);
	int ans = 0;
	for (int i = 0; i < 5; i++) {
		ans += v[i].first;
		s.insert(v[i].second + 1);
	}
	cout << ans << "\n";
	for (auto iter = s.begin(); iter != s.end(); iter++) cout << *iter << " ";

	return 0;
}