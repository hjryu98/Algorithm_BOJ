#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <iostream>
using namespace std;
int n;
struct stack {
	int arr[1000002] = { 0, };
	int len = 0;

	void one(int x) {
		arr[len++] = x;
	}

	int two() {
		if (!len) return -1;
		int val = arr[len - 1];
		arr[len - 1] = 0;
		len--;

		return val;
	}

	int three() {
		return len;
	}

	int four() {
		return ((len <= 0) ? 1 : 0);
	}

	int five() {
		if (!len) return -1;
		return arr[len - 1];
	}

};
stack st;

int main() {
	fastio;
	cin >> n;
	while (n--) {
		int a;
		cin >> a;
		if (a == 1) {
			int b;
			cin >> b;
			st.one(b);
		}
		else if (a == 2) {
			cout << st.two() << "\n";
		}
		else if (a == 3) {
			cout << st.three() << "\n";
		}
		else if (a == 4) {
			cout << st.four() << "\n";
		}
		else {
			cout << st.five() << "\n";
		}
	}

	return 0;
}