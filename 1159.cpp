#include <iostream>
using namespace std;
int n;
bool flag;
int check[30];
int main() {
	string st;
	cin >> n;
	while (n--) {
		cin >> st;
		check[st[0] - 'a']++;
	}

	for (int i = 0; i < 26; i++) {
		if (check[i] >= 5) {
			flag = true;
			cout << (char)(i + 'a');
		}
	}
	if (!flag) cout << "PREDAJA";

	return 0;
}