#include <iostream>
#include <stack>
using namespace std;
int n, ans;

bool solve(string &str) {
	stack <char> st;

	for (int i = 0; i < str.size(); i++) {
		char cur = str[i];
		if (st.empty()) st.push(cur);
		else {
			if (st.top() == cur) st.pop();
			else st.push(cur);
		}
	}
	return st.empty();
}

int main() {
	cin >> n;
	while (n--) {
		string str;
		cin >> str;
		ans += solve(str);
	}
	cout << ans;

	return 0;
}