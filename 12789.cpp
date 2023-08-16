#include <iostream>
#include <stack>
#include <queue>
using namespace std;
stack <int> st;
queue <int> q;
int n;
int cur = 1;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		q.push(a);
	}

	while (!q.empty()) {
		int val = q.front();

		if (val == cur) {
			q.pop();
			cur++;
		}
		else if (!st.empty() && st.top() == cur){
			st.pop();
			cur++;
		}
		else {
			q.pop();
			st.push(val);
		}
	}

	while (!st.empty()) {
		if (st.top() != cur) {
			cout << "Sad";
			return 0;
		}
		else {
			st.pop();
			cur++;
		}
	}
	cout << "Nice";

	return 0;
}