#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
string st;

string change(int x) {
	string str;
	int idx = 0;
	int res[10005] = { 0, };
	while (x) {
		int a = x % 10;
		res[idx++] = a;
		x /= 10;
	}

	for (int i = idx - 1; i >= 0; i--) {
		str += (res[i] + '0');
	}

	return str;
}


int main() {
	cin >> st;
	int size = st.size();

	if (st == "0") {
		cout << "W";
		return 0;
	}

	string ans = "";
	int num = 0;

	for (int i = 0; i < size; i++) {
		if (st[i] == '-') {
			ans += "-";
		}

		else if (st[i] == '+') {
			ans += "+";
		}

		else if (st[i] == 'x') {
			if (!num) {
				ans += "0.5xx";
			}
			else {
				num /= 2;

				string str = change(num);

				if (str != "1") ans += str;
				ans += "xx";
				num = 0;
			}
		}
		else {
			int j;
			string tmp = "";
			for (j = i;; j++) {
				if (st[j] < '0' || st[j] > '9') break;
				tmp += st[j];
			}
			i = j - 1;
			num = stoi(tmp);
		}
	}
	if (num != 0) {
		string str = change(num);

		if(str != "1") ans += str;
		ans += "x";
		num = 0;
	}
	
	ans += "+W";
	cout << ans;

	return 0;
}