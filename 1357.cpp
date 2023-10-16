#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int a, b;
int rev(int a) {
	string st = to_string(a);
	reverse(st.begin(), st.end());
	return stoi(st);
}
int main() {
	cin >> a >> b;
	cout << rev(rev(a) + rev(b));
	return 0;
}