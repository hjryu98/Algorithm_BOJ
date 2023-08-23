#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector <string> v;
int n;
bool comp(string a, string b) {
	if (a.size() == b.size()) return a.compare(b) < 0;
	return a.size() < b.size();
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	sort(v.begin(), v.end(), comp);
	for (int i = 0; i < v.size(); i++) cout << v[i] << "\n";

	return 0;
}