#include <iostream>
using namespace std;
int a, b;
int main() {
	while (cin >> a >> b) {
		if (a == b && a == 0) break;

		if (a % b != 0 && b % a != 0) cout << "neither\n";
		else if (a % b == 0) cout << "multiple\n";
		else if (b % a == 0) cout << "factor\n";
	}

	return 0;
}