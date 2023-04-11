#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <iostream>
#include <map>
using namespace std;
int n, m;
map <string, string> mm;
int main() {
	fastio;
	cin >> n >> m;

	while (n--) {
		string a, b;
		cin >> a >> b;
		mm[a] = b;
	}
	while (m--) {
		string a;
		cin >> a;
		cout << mm[a] << "\n";
	}

	return 0;
}