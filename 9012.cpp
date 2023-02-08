#include <iostream>
#include <stack>
using namespace std;
int t;
int main() {
	cin >> t;
	while (t--) {
		stack <int> s;
		string st;
		bool flag = true;

		cin >> st;
		int len = st.size();

		for (int i = 0; i < len; i++) {
			if (st[i] == '(') s.push(1);
			else {
				if (s.empty()) {
					flag = false;
					break;
				}
				else s.pop();
			}
		}
		if (!s.empty()) flag = false;
		
		if (flag) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}