#include <iostream>
#include <string>
using namespace std;

int main() {
	while (1) {
		string st;
		getline(cin, st);
		if (st.compare("END") == 0) break;
		int len = st.size();
		for (int i = len - 1; i >= 0; i--) cout << st[i];
		cout << "\n";
	}

	return 0;
}