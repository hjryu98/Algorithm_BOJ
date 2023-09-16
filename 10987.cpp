#include <iostream>
using namespace std;
string str;
int cnt;
int main() {
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		char cur = str[i];

		if (cur == 'a' || cur == 'e' || cur == 'i' || cur == 'o' || cur == 'u') cnt++;
	}
	cout << cnt;

	return 0;
}