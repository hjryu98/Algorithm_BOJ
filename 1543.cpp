#include <iostream>
#include <string>
using namespace std;
string a, b;
int ans;
bool check(int lena, int lenb, int cur) {
	for (int j = 0; j < lenb; j++) {
		if (a[cur + j] != b[j]) return false;
	}
	
	return true;
}

int main() {
	getline(cin, a);
	getline(cin, b);
	int lena = a.size(); int lenb = b.size();

	for (int i = 0; i < lena; i++) {
		if (b[0] != a[i])  continue;
		if (check(lena, lenb, i)) {
			i += (lenb - 1);
			ans++;
		}
	}
	cout << ans;

	return 0;
}