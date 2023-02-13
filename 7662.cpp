#include <iostream>
#include <set>
using namespace std;
int t;
int main() {
	cin >> t;
	while (t--) {
		multiset <int> ms;
		int k;
		cin >> k;

		while (k--) {
			char ch;
			int a;
			cin >> ch;
			if (ch == 'I') {
				cin >> a;
				ms.insert(a);
			}
			else {
				cin >> a;
				if (ms.empty()) continue;
				if (a == 1) ms.erase(--ms.end());
				else ms.erase(ms.begin());
			}
		}
		if (ms.empty()) cout << "EMPTY\n";
		else {

			cout << *ms.rbegin() << " " << *ms.begin() << "\n";
		}
	}

	return 0;
}