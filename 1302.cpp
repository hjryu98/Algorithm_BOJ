#include <iostream>
#include <map>
using namespace std;
string cur;
int n, ans;
map <string, int> mm;
int main() {
	cin >> n;
	while (n--) {
		string a;
		cin >> a;
		mm[a]++;
		if (mm[a] > ans) {
			cur = a;
			ans = mm[a];
		}
		else if (mm[a] == ans) {
			cur = (cur.compare(a) > 0 ? a : cur);
		}
	}
	cout << cur;

	return 0;
}