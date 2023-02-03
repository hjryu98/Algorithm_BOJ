#include <iostream>
#include <string>
using namespace std;
string a, b;
int mn, mx;
int main() {
	cin >> a >> b;
	int lena = a.size();
	int lenb = b.size();

	string mna, mnb;
	for (int i = 0; i < lena; i++) {
		if (a[i] == '6') mna += '5';
		else mna += a[i];
	}
	for (int i = 0; i < lenb; i++) {
		if (b[i] == '6') mnb += '5';
		else mnb += b[i];
	}

	int vala = stoi(mna);
	int valb = stoi(mnb);

	mn = vala + valb;

	mna.clear();
	mnb.clear();

	for (int i = 0; i < lena; i++) {
		if (a[i] == '5') mna += '6';
		else mna += a[i];
	}
	for (int i = 0; i < lenb; i++) {
		if (b[i] == '5') mnb += '6';
		else mnb += b[i];
	}

	vala = stoi(mna);
	valb = stoi(mnb);

	mx = vala + valb;
	cout << mn << " " << mx;

	return 0;
}