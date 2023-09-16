#include <iostream>
#include <map>
using namespace std;
int n;
map <string, int> mm;
int main() {
	cin >> n;
	while (n--) {
		string str;
		cin >> str;

		int idx = str.find(".");
		string file = str.substr(idx + 1, str.size() - idx - 1);
		mm[file]++;
	}
	for (auto iter = mm.begin(); iter != mm.end(); iter++) {
		string cur = (*iter).first;
		int cnt = (*iter).second;

		cout << cur << " " << cnt << "\n";
	}

	return 0;
}