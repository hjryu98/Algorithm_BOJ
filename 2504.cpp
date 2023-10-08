#include <iostream>
#include <stack>
using namespace std;
string str;
stack <int> st;
int main() {
	cin >> str;

	int len = str.size();
	// ( -1 [ -2
	for (int i = 0; i < len; i++) {
		char cur = str[i];

		if (cur == '(') {
			st.push(-1);
		}

		else if (cur == '[') {
			st.push(-2);
		}

		else if (cur == ')') {
			int val = 0;
			bool flag = false;
			if (st.empty()) {
				cout << 0;
				return 0;
			}

			while (!st.empty()) {
				if (st.top() > 0) {
					val += st.top();
					st.pop();
				}
				else if (st.top() == -1) {
					st.pop();
					flag = true;
					break;
				}
				else {
					cout << 0;
					return 0;
				}
			}
			if (!flag) {
				cout << 0;
				return 0;
			}

			if (val == 0) st.push(2);
			else st.push(2 * val);
		}

		else if (cur == ']') {
			int val = 0;
			bool flag = false;
			if (st.empty()) {
				cout << 0;
				return 0;
			}

			while (!st.empty()) {
				if (st.top() > 0) {
					val += st.top();
					st.pop();
				}

				else if (st.top() == -2) {
					st.pop();
					flag = true;
					break;
				}

				else {
					cout << 0;
					return 0;
				}
			}
			if (!flag) {
				cout << 0;
				return 0;
			}

			if (val == 0) st.push(3);
			else st.push(3 * val);
		}
	}
	int ans = 0;
	while (!st.empty()) {
		if (st.top() < 0) {
			cout << 0;
			return 0;
		}
		ans += st.top();
		st.pop();
	}
	cout << ans;

	return 0;
}