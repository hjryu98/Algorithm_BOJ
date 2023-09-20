#include <iostream>
#include <string>
using namespace std;
string str;
int main() {
	while (1) {
		int cnt = 0;
		getline(cin, str);
		for (int i = 0; i < str.size(); i++) str[i] = tolower(str[i]);
		if (str.compare("#") == 0) break;

		for (int i = 0; i < str.size(); i++) {
			if (str[i] == 'a' || str[i] == 'e' || str[i] == 'o' || str[i] == 'i' || str[i] == 'u') cnt++;
		}
		cout << cnt << "\n";
	}

	return 0;
}