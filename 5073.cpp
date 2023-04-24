#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	while (1) {
		vector <int> v;
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back(a);
		v.push_back(b);
		v.push_back(c);

		if (a == b && b == c && a == 0) break;

		sort(v.begin(), v.end());
		if (v[0] + v[1] <= v[2]) {
			cout << "Invalid\n";
			continue;
		}
		v.erase(unique(v.begin(), v.end()), v.end());
		if (v.size() == 1) cout << "Equilateral\n";
		else if (v.size() == 2) cout << "Isosceles\n";
		else cout << "Scalene\n";
	}

	return 0;
}