#include <iostream>
#include <string>
using namespace std;
using ll = long long;
string a, b, c, d;
int main() {
	cin >> a >> b >> c >> d;
	a += b;
	c += d;
	/*
	https://blockdmask.tistory.com/333
	*/
	ll one = stoll(a);
	ll two = stoll(c);
	cout << one + two;

	return 0;
}