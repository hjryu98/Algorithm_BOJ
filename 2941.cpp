#include <iostream>
#include <set>
using namespace std;
set <string> s;
string st;
int ans;
int main() {
	s.insert("c=");
	s.insert("c-");
	s.insert("dz=");
	s.insert("d-");
	s.insert("lj");
	s.insert("nj");
	s.insert("s=");
	s.insert("z=");

	cin >> st;
	int size = st.size();

	for (int i = 0; i < size; i++) {
		string tmp;

		if (st[i] == 'c' || st[i] == 'd' || st[i] == 'l' || st[i] == 'n' || st[i] == 's' || st[i] == 'z') {
			tmp += st[i];
			if (st[i] != 'd') {
				tmp += st[i + 1];
				if (s.count(tmp)) {
					ans++;
					i++;
				}
				else ans++;
			}
			else {
				if (st[i + 1] == '-') {
					ans++;
					i++;
				}
				else if (st[i + 1] == 'z') {
					if (st[i + 2] == '=') {
						ans++;
						i += 2;
					}
					else {
						ans += 2;
						i++;
					}
				}
				else ans++;
			}
		}
		else ans++;
	}
	cout << ans;

	return 0;
}