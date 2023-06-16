#include <iostream>
#include <string>
using namespace std;
string arr[] = { "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ" };
int main() {
	string st;
	int ans = 0;
	cin >> st;
	int len = st.size();
	
	for (int i = 0; i < len; i++) {
		char cur = st[i];

		for (int j = 0; j < 8; j++) {
			if (arr[j].find(cur) == string::npos) continue;
			
			ans += j + 3;
			break;
		}
	}
	cout << ans;

	return 0;
}