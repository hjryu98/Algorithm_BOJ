#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <iostream>
#include <vector>
#include <set>
using namespace std;
set <string> st;
vector <string> ans;
int main() {
	fastio;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string a, b;
		cin >> a >> b;
		if (b.compare("enter") == 0) st.insert(a);
		else st.erase(a);
	}

	for (auto iter = st.begin(); iter != st.end(); iter++) {
		ans.push_back(*iter);
	}
	for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i] << "\n";

	return 0;
}